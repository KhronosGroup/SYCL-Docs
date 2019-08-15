#!/bin/bash

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
