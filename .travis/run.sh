#!/bin/bash

set -ex

if [[ "$(uname -s)" == 'Darwin' ]]; then
    if which pyenv > /dev/null; then
        eval "$(pyenv init -)"
    fi
    pyenv activate conan
fi

conan config install conan

mkdir build
cd build
conan install .. --profile default --profile sycl-spec-buildtools
conan build .. --package-folder ../package
