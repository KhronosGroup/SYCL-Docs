#!/bin/bash
# Copyright (c) 2011-2020 The Khronos Group, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

git config user.name "Travis CI Bot"
git config user.email "webmaster@khronos.org"

git clone "https://github.com/${TRAVIS_REPO_SLUG}" repo --single-branch
pushd repo >/dev/null

git checkout --orphan gh-pages
git rm -rf -q .

cp -a ../package/share/doc/sycl .
git add -A .
git commit -am 'Deploy to GitHub Pages'
git push --force -u "https://${GITHUB_TOKEN}@github.com/${TRAVIS_REPO_SLUG}" gh-pages
