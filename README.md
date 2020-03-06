![SYCL Logo](latex/logos/SYCL_RGB_June16-inkscape-1500.png)

![Build Status](https://api.travis-ci.com/KhronosGroup/SYCL-Docs.svg?branch=master)
[![SPEC master](https://img.shields.io/badge/SPEC-master-red.svg?logo=adobe-acrobat-reader)](https://khronosgroup.github.io/SYCL-Docs/sycl/sycl.pdf)
[![SPEC 1.2.1-6](https://img.shields.io/badge/SPEC-1.2.1--6-orange.svg?logo=adobe-acrobat-reader)](https://www.khronos.org/registry/SYCL/specs/sycl-1.2.1.pdf)
[![Join the Slack group](https://img.shields.io/badge/chat-on%20slack-blue.svg?logo=slack)](https://khr.io/slack)

# SYCL Open Source Specification

This repository contains the source and tool chain used to generate
the formal SYCL specifications found on [https://www.khronos.org/sycl/](https://www.khronos.org/sycl/).

## Building

For getting the dependencies the [Conan package manager](https://conan.io/) can be used. Building this way is more feature-complete, as it tracks all input files as dependencies of the `.pdf`, supports out-of-tree builds and downsamples/converts images for a smaller output.

Packagers and distributors are advised to build the specification using this approach (or by calling CMake directly), since this will create an FHS-like directory structure with symlinks set up. Please refer to the `conanfile.py` for a full list of all dependencies.

```bash
# First time setup
pip install --upgrade conan
conan user
conan remote add conan-center https://api.bintray.com/conan/conan/conan-center
conan remote add mmha https://api.bintray.com/conan/mmha/public-conan

# To actually build the spec in the top directory of the worktree:
conan install . --install-folder build --profile default --profile conan/profiles/sycl-spec-buildtools
conan build . --build-folder build
conan package . --build-folder build --package-folder package
```

This generates the following tree:

```
package
└── share
    └── doc
        └── sycl
            ├── <version>
            │   ├── sycl-<version>-<revision>.pdf
            │   └── sycl-<version>.pdf -> sycl-<version>-<revision>.pdf
            └── sycl.pdf -> <version>/sycl-<version>.pdf
```

### Without Conan
To build the PDF you need the LaTeX framework installed.

A good start on Debian/Ubuntu for example is to install the
`texlive-full` and `make` packages.

### Using Plain CMake
In addition to LaTeX, you will need CMake ≥ 3.13 and
[UseLATEX](https://gitlab.kitware.com/kmorel/UseLATEX).

```bash
cmake -S <path/to/this/repo> \
      -B build \
      -D UseLATEX_ROOT=<path/to/UseLATEX.cmake> \
      [-DCMAKE_INSTALL_PREFIX=package]
cmake --build build [--target install]
```

If installed, this will produce the same tree as above.

---
### Using GNU Make
To build the PDF you need the LaTeX framework installed.

A good start on Debian/Ubuntu for example is to install the
`texlive-full` and `make` packages.

To build the PDF specification:
```
cd latex
make
```
and it should produce the file `sycl-1.2.1.pdf`.
