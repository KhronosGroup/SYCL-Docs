![SYCL Logo](adoc/logos/SYCL_RGB_June16-inkscape-1500.png)

[//]: # "to update to newer CI when going public ![Build Status](https://api.travis-ci.com/KhronosGroup/SYCL-Docs.svg?branch=master)""
[//]: # "to update to newer CI when going public [![SPEC master](https://img.shields.io/badge/SPEC-master-red.svg?logo=adobe-acrobat-reader)](https://khronosgroup.github.io/SYCL-Docs/sycl/sycl.pdf)"
[![SPEC master](https://img.shields.io/badge/SPEC-master-red.svg?logo=adobe-acrobat-reader)](https://gitlab.khronos.org/sycl/Specification/-/jobs)
[![SPEC 2020-1](https://img.shields.io/badge/SPEC-2020--1-orange.svg?logo=adobe-acrobat-reader)](https://www.khronos.org/registry/SYCL/specs/sycl-2020-provisional.pdf)
[![Join the Slack group](https://img.shields.io/badge/chat-on%20slack-blue.svg?logo=slack)](https://khr.io/slack)

# SYCL Open Source Specification

This repository contains the source and tool chain used to generate
the formal SYCL specifications found on [https://www.khronos.org/sycl/](https://www.khronos.org/sycl/).

## Reading the latest version of the SYCL specification

The GitLab CI pipeline builds the specification. This is accessible
from this page, under the green check symbol, on the top right of the
page or more generally from the rocket symbol on the left side.

Then on the pipeline page, select the *Jobs* tab and click on the
*download* icon on the bottom right.


## Building the SYCL specification

### Using GitLab CI

The simplest way to build the specification is not to actually build
it, but to rely on the Khronos continuous integration process which
builds automatically a branch when it is changed on
https://gitlab.khronos.org/sycl/Specification

Look at CI/CD-Jobs (the rocket-ship icon on the left menu bar or
https://gitlab.khronos.org/sycl/Specification/-/jobs), click on the
`Download` icon for the latest CI job in the branch of interest or
click on `Passed` to dive into more details. Once unzipping the
compilation artifacts, look inside `adoc/out` directory to find the
HTML and PDF version.

Note that to read the HTML specification correctly with all the
mathematical symbols, you need also to have the `katex` directory
along the `html` one. This might not be the case if your downloading
framework lazily unzips just what you read.

You can use this CI infrastructure while developing: you can git-push
or git-force-push your branch on the server and go to CI/CD-Jobs to
look at the compiled version.

All this works because of the existing `.gitlab-ci.yml` recipe.

### Using pre-configured AsciiDoctor-capable Docker image

Compiling the specification requires some specific AsciiDoctor related
packages.

To simplify the setup, Khronos provides a pre-configured Docker Linux
Ubuntu image you can use on a Docker executor to compile the
specification on various OS able to run Docker.

Assuming you are on Debian/Ubuntu Linux, the first time you need to
install Docker with for example:
```bash
sudo apt update
sudo apt install docker.io
```

The base image used to build the specifications can be downloaded or
updated to the latest version via
```bash
docker pull khronosgroup/docker-images:vulkan-docs-base
```
Or you can manually generate the image using the script provided in
`https://github.com/KhronosGroup/DockerContainers`.


To compile the specification you can rely on the `Makefile` inside the
`adoc` directory, for example with:
```bash
cd adoc
make clean docker-html docker-pdf
```

There are a few variables defined in the `Makefile` you can set to
change the behavior, such as to display verbosely the compilation
process:
```bash
make QUIET= clean docker-html docker-pdf
```

If you need to launch explicitly Docker without using `make` on the
host, look at the `adoc/Makefile` and imitate on your system how
Docker is launched.

Since the Docker image is old, there is a new path using a script to
upgrade the files inside the Docker image to be used as:
```bash
make DOCKER_COMMAND="make QUIET= --directory=/sycl/adoc clean html pdf" dock
```

### Using native computer

If you are using a Debian/Ubuntu Linux distribution, you can look at
how the previous process works and how the Docker image is done at
https://github.com/KhronosGroup/DockerContainers and specifically
https://github.com/KhronosGroup/DockerContainers/blob/master/Dockerfile.vulkan-docs-base
which gives an idea of the packages to install and
https://github.com/KhronosGroup/DockerContainers/blob/master/entrypoint.vulkan.sh

*TODO*: find the minimal recipe.
```bash
sudo apt update
sudo apt install bison \
  build-essential \
  cmake \
  flex \
  fonts-lyx \
  g++ \
  ghostscript \
  git \
  libcairo2-dev \
  libffi-dev \
  libgdk-pixbuf2.0-dev \
  libpango1.0-dev \
  libreadline-dev \
  libxml2-dev \
  nodejs \
  node-escape-string-regexp \
  node-he \
  node-lunr \
  poppler-utils \
  python3 \
  ruby-dev

sudo apt clean

sudo gem install asciidoctor \
  asciidoctor-diagram \
  asciidoctor-mathematical \
  asciidoctor-pdf \
  coderay \
  json-schema \
  i18n \
  pygments.rb \
  rouge \
  text-hyphen
```

Then use for example:
```bash
make QUIET= clean html pdf
```

There is also some discussion back-ground in
https://gitlab.khronos.org/sycl/Specification/-/merge_requests/484#note_270338


### Windows recipe

*TODO*: Investigate the Docker route
https://docs.docker.com/docker-for-windows/install/ , WSL2, CygWin,
VCPKG...
