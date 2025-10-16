![SYCL Logo](adoc/logos/SYCL_RGB_June16-inkscape-1500.png)

<!-- to update to newer CI when going public ![Build Status](https://api.travis-ci.com/KhronosGroup/SYCL-Docs.svg?branch=master) -->
<!-- to update to newer CI when going public [![SPEC master](https://img.shields.io/badge/SPEC-master-red.svg?logo=adobe-acrobat-reader)](https://khronosgroup.github.io/SYCL-Docs/sycl/sycl.pdf) -->
[![SPEC 2020-10](https://img.shields.io/badge/SPEC-2020--10-orange.svg?logo=adobe-acrobat-reader)](https://www.khronos.org/registry/SYCL/specs/sycl-2020/pdf/sycl-2020.pdf)
[![SPEC 2020-10](https://img.shields.io/badge/SPEC-2020--10-orange.svg?logo=HTML5)](https://www.khronos.org/registry/SYCL/specs/sycl-2020/html/sycl-2020.html)
[![SPEC latest](https://img.shields.io/badge/SPEC-latest-red.svg?logo=adobe-acrobat-reader)](https://github.com/KhronosGroup/SYCL-Docs/actions?query=branch%3ASYCL-2020%2Fmaster+is%3Asuccess)
[![Join the Slack group](https://img.shields.io/badge/chat-on%20slack-blue.svg?logo=slack)](https://khr.io/slack)

# SYCL Open Source Specification

This repository contains the source markup used to generate the
formal SYCL specifications found on
[https://www.khronos.org/sycl/](https://www.khronos.org/sycl/).

If you are proposing a merge or pull request to the specification, this
README describes how the specification HTML and PDF targets can be built.
Proposed changes must successfully build these targets before being
considered for inclusion by the SYCL Working Group.


## Building the SYCL specification


### Building using Github CI

When using our github repository, pushing to a branch will trigger the
Github Actions CI script under `../.github/workflows/CI.yml` to build HTML
and PDF versions of the spec. To see the outputs, click on the `Actions` tab
in the top navigation bar, or go to
https://github.com/KhronosGroup/SYCL-Docs/actions . Your commit should show
up on the list of commits below. Click through to the Actions summary for
that commit.

On success, a green checkmark will appear by the commit name on this page.
Output artifacts can be downloaded as a zipfile from the `Artifacts` section
near the bottom of the page.

On failure, a red `x` will appear by the commit name. Click through to the
`build` job and it should auto-scroll to the CI log showing where the build
failed. Fix it and push a new commit to try again.

Note that to read the HTML specification correctly with all the
mathematical symbols, you need also to have the `katex` directory
along the `html` one. This might not be the case if your downloading
framework lazily unzips just what you read.

If you are proposing a pull request from your own clone of our repository,
you may need to enable Github Actions for your clone.


### Building Using The Khronos Docker Image

Building the specification on your own machine requires a large set of
tools. Rather than installing these tools yourself, if you can run Docker on
a Linux compatible host (probably including Windows WSL2 with a Ubuntu or
Debian OS, and possibly including MacOS X), you can use the same
pre-configured Docker image used by the CI builds.

If you are on Debian/Ubuntu Linux, install Docker with:

```bash
sudo apt update
sudo apt install docker.io
```

The Docker image used to build the specifications can then be downloaded or
updated to the latest version via

```bash
docker pull khronosgroup/docker-images:asciidoctor-spec
```

The Dockerfile specifying this image can be found at
https://github.com/KhronosGroup/DockerContainers if you need to build a
modified or layered image. However, if something is missing or out of date
in the image, please file an issue on the `DockerContainers` repository
before trying to build your own image. We will try to keep the image updated
as needed.

To build the specification using the image, use the `Makefile` inside the
`adoc` directory:

```bash
cd adoc
make clean docker-html docker-pdf
```

Outputs will be located in $(OUTDIR) (by default, `out/` in the `adoc`
directory).

There are some variables defined in the `Makefile` you can set to change the
behavior, such as to verbosely display the build process:

```bash
make QUIET= clean docker-html docker-pdf
```

If you need to invoke Docker without using `make` on the host, look at the
actions in the `docker-%` target in `adoc/Makefile` and replicate them on
your system.


### Building On Your Native Machine

If you don't want to, or can't use Docker (or a compatible replacement - it
is possible that the Red Hat `podman` tool can run our Docker container, for
example, though we do not support this), then you will need to install all
the same tools in your own environment.

We cannot provide instructions to do this on every possible build
environment. However, if you are using Debian/Ubuntu Linux, either native or
via WSL2, you should be able to install the required tools by looking at the
Dockerfile at

https://github.com/KhronosGroup/DockerContainers/blob/master/asciidoctor-spec.Dockerfile

Note that the Khronos Docker image layers on the official Ruby 3.1 Docker
image, so you must install Ruby first.

If you have installed an older version of the tools and the Khronos image is
updated, there may be minor changes in the Makefile and markup required by
the new versions. For example, updating from asciidoctor-pdf 1.6.1 to 2.2.0
required changing the `pdf-stylesdir` attribute in the asciidoctor build to
`pdf-themesdir`. Eventually, these changes may make using the older tools
impractical. If this happens, update your tools to match the latest Docker
image, and rebase your working branch on current `main` branch.


### Building Using GitLab CI

Finally, if you are a Khronos member working in our internal Gitlab server,
Gitlab CI builds the image just like Github CI. Go to the
`...sycl/Specification` repository page on the gitlab server, click through
to CI/CD-Jobs (the rocket-ship icon on the left menu bar or
`...sycl/Specification/-/jobs`). If your job succeeded, click on the
`Download` icon for the latest CI job in the appropriate branch to download
the zip file of build artifacts, or click on `Passed` to see build details.

The Gitlab CI script is functionally equivalent to the Github CI script, but
is located under `.gitlab-ci.yml`, using a different YAML scheme.
