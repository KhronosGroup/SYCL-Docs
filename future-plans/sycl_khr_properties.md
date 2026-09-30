# Plan for adopting sycl\_khr\_properties into core spec

## The current situation with the properties KHR

The sycl\_khr\_properties extension adds a new property mechanism to SYCL, which
is completely independent from the properties in the core SYCL 2020
specification.
An application can use both types of properties simultaneously so long as the
new-style properties from sycl\_khr\_properties are added only to the new-style
property container `sycl::khr::properties` and the old-style properties from the
core specification are added only to the old-style container
`sycl::property_list`.
This restriction falls out naturally because the `sycl::khr::properties`
constructor has a constraint that its properties all have the
`sycl::khr::is_property` trait, and the `sycl::property_list` constructor has a
constraint that all its properties have the `sycl::is_property` trait.
These are different traits in different namespaces.
The `sycl::khr::is_property` trait classifies only the new-style properties, and
the `sycl::is_property` trait classifies only the old-style properties.

This strict separation of properties seems reasonable.
Each function in the core specification that takes a `sycl::property_list` has a
corresponding overload in the KHR that takes a `sycl::khr::properties`, and each
property in the core specification has a corresponding new-style property in the
KHR.
Therefore, applications can use either the new-style properties or the old-style
properties when calling any of the functions in the core specification, and it
is safe for an application to pass new-style properties to some functions while
passing old-style properties to others.
We do not allow a single function call to take a mixture of new- and old-style
properties, but it does not seem like a burden to require applications to adopt
one property style for any single function call.

## Goal of adopting KHR properties into the core specification

We would only adopt the properties from sycl\_khr\_properties into a future
version of the core specification if we have a goal of deprecating the existing
properties in the SYCL 2020 specification.
The goal in this case would be to migrate SYCL applications to the new property
style.
Of course, the old-style properties would still be supported for some time, but
we would eventually remove them from some future version of the core
specification.
This process would take at least two major releases of the core specification.
For example, the SYCL-Next specification might adopt the new-style properties
and also deprecate the old-style properties.
Then, we might remove the old-style properties in SYCL-Next-Next.
At that point, applications would either need to migrate to the new-style
properties or stick with the SYCL-Next release.

The key thing to note here is that both property styles will be supported in the
core specification for some period of time.
Therefore, we need a plan for how both property styles will coexist in this
scenario.

## API conflict if we adopt the KHR properties into the core specification

If we decide to adopt the properties from sycl\_khr\_properties into a future
version of the core specification, most of the APIs will remain distinct.
For example, the `properties` and `property_list` containers are different
type names, so they can both safely live in the `sycl` namespace.
Most of the properties themselves will also remain distinct because the SYCL
2020 core properties (mostly) live in the `sycl::property::XXX` namespaces,
where `XXX` is the name of the class to which the property belongs.
(For example, queue related properties live in the `sycl::property::queue`
namespace.)
By contrast, the new-style properties don't live in the `XXX` sub-namespace, so
after adopting them into the core specification, they would live directly in
`sycl::property`.

There are only two identifiers that will conflict if we adopt the new-style
properties into the core specification: the `is_property` (and `is_property_v`)
trait, and the `no_init` property.
The `no_init` property is an outlier in the core SYCL 2020 specification because
it is the only property that doesn't live in an `XXX` sub-namespace.
None of the other traits conflict because no other trait has the same name in
both property styles.

## Managing the conflicting `is_property` trait

It makes sense for the `sycl::is_property` trait to classify both new-style and
old-style properties as "true".
However, this trait is used as a constraint for both the `sycl::properties` and
the `sycl::property_list` constructors.
Since we don't want to allow mixing of property styles in the two containers, we
need to adjust the constraints somehow.

We can do this by adding a new trait `sycl::is_deprecated_property` at the time
we adopt the the new-style properties into the core specification.
This trait will classify only the old-style properties as "true".
We can then adjust the constraints on the `sycl::properties` and
`sycl::property_list` constructors accordingly.

It makes sense to mark the `sycl::is_deprecated_property` trait as deprecated
immediately as soon as we add it.
This trait is needed only so long as we have the old-style properties, and it
can be removed whenever we decide to remove them from the core specification.

## Managing the conflicting `no_init` property

TODO: I think there are several ways to deal with this.
The simplest would be to name the equivalent new-style property something else,
which would avoid the conflict.
Since the draft KHR doesn't even contain this property yet, let's wait before
filling in this section.

## Alternate solution (rejected)

Another possibility is to allow `sycl::properties` and `sycl::property_list` to
contain a mixture of both new- and old-style properties.
Although this is possible, it adds implementation and testing burden, and it's
not clear why it would really benefit application developers.
(See the reasoning above.)
Nevertheless, this section describes what we would need to do in order to follow
this path.

Each old-style property behaves like a new-style property whose values are all
runtime-supplied.
It is therefore theoretically possible for a `properties` container to contain a
mixture of new-style properties and old-style properties.
It is also possible for a `property_list` container to contain a mixture of
old-style properties and new-style properties whose values are all
runtime-supplied.

The first hurdle, then, is to define a trait like `is_property_runtime` that can
classify those properties (both new- and old-style) whose values are all
runtime-supplied.
We can then use this trait as a constraint on the `property_list` constructor.

In order to add old-style properties to the new-style `properties` container, we
need to define the concept of a "key" for these properties.
Old style properties do not currently have a key, but the name of the property
itself can serve as a key.
Therefore, we would want to change the trait `is_property_key` such that it
classifies all the old style properties as "true".
(Thus, the traits `is_property` and `is_property_key` would both return "true"
for an old-style property.)
Implementations would, therefore, need to treat each old-style property as both
a property and a key.

The functions that take a `properties` parameter all have a constraint on the
type of that parameter which uses the `is_property_list_for` and
`is_property_for` traits.
Therefore, we would need to define the `is_property_for` trait for each
old-style property such that it returns "true" for the appropriate tag classes.

Once we do this, it will be possible for applications to pass either a
`properties` or a `property_list` to functions, even if they contain a mixture
of new- and old-style properties.

The implementation of each function would need to change such that it recognized
either the new- or the equivalent old-style property.

The implementation of the old-style `has_property` and `get_property` functions
deserves some explanation.
Because old-style properties do not have a "key", these functions expect the
name of a property (not a property key) as their template parameter.
Therefore, applications wanting to use these functions to query new-style
properties would pass the property itself instead of the property's key.
