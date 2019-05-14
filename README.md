# SYCL-Docs
SYCL Open Source Specification

This repository contains the source and tool chain used to generate
the formal SYCL specifications found on https://www.khronos.org/sycl/

## Building

To build the PDF you need the LaTeX framework installed.

A good start on Debian/Ubuntu for example is to install the
`texlive-full` and `make` packages.

To build the PDF specification:
```
cd latex
make
```
and it should produce the file `sycl-1.2.1.pdf`.
