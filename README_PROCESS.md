## Repository branch structure

The SYCL specification intends to have periodic major versions, where each is
named according to the year in which it is approved by the working group.
Although there were previous major versions, this repository starts with the
SYCL 2020 specification.
From this point forward, the SYCL specification is "unified", meaning that a
single document serves as the official specification for all major versions
from SYCL 2020 onwards.

Depending on the release cycle, there is either one active branch named "main"
or two active branches named "main" and "sycl-xxxx" (where "xxxx" is a 4 digit
year).
In order to understand these branches, it may help to describe the current
structure and how things will change in the future.
At present, we have branches named "main" and "sycl-2020".
The "sycl-2020" branch corresponds to the SYCL 2020 specification, which is a
published major version.
The "main" branch corresponds to the next major version of the SYCL
specification (SYCL-Next), which is currently in development.
Both branches are active at this point.
Bug fixes and clarifications go into both branches, while new content that is
specific to the SYCL-Next version goes only into "main".
This allows us to work on SYCL-Next while we still make update revisions to SYCL
2020.

Once SYCL-Next is published, it will also be the official specification for SYCL
2020 because the specification document is "unified".
Therefore, there is no need to maintain the "sycl-2020" branch anymore, and we
will remove it at this point.
(We will still have tags that identify each publication of the SYCL 2020
specification.)
Therefore, once SYCL-Next is published, we will have only one active branch named
"main".
Any bug fixes or clarifications to the SYCL-Next specification will be made to
the "main" branch at this point, and we will publish update revisions from this
branch.

At some later point, we will start development of another major release
SYCL-Next2.
Immediately before making the first commit that is specific to SYCL-Next2, we
will create a branch named "sycl-xxxx" (where "xxxx" represents the year in
which SYCL-Next was approved by the working group).
Bug fixes and clarifications to SYCL-Next will happen on this "sycl-xxxx" branch
while new development happens on "main".


## Cherry pick strategy

Because most changes should be made to the most current specification, we
normally draft PRs against the "main" branch.
Once a PR is merged, we may also cherry pick it to the "sycl-xxxx" branch if
the change is a clarification (and if the "sycl-xxxx" branch exists).

We currently use a manual process for these cherry picks, though we would like
to create a script to help automate these steps in the future.

* Start with the "sycl-xxxx" branch checked out at its head.

* Create a local branch to represent the cherry pick, for example
  `git checkout -b cherry-pick-NNN`.

* Run `git cherry-pick -x -m 1 <commit>` where `<commit>` is the merge commit of
  some merged PR that we want to cherry pick from "main".
  Resolve any merge conflicts if necessary.

* Use `git commit --amend` to rewrite the commit message.
  Rewrite the commit message from:

  ```
  Merge pull request #NNN from branch

  Summary of PR

  (cherry picked from commit ID)
  ```

  to:

  ```
  Summary of PR

  Cherry pick #NNN from main
  (cherry picked from commit ID)
  ```

* If the merge was not clean, verify that the specification still builds and
  looks OK.

* Push the branch to GitHub and create a new PR.
  Be sure to change the PR "base" branch to "sycl-xxxx".

* Once the CI tests pass, you can immediately merge the PR with a PR comment
  like "Merging because the WG already approved #NNN".

Although this process is a bit more verbose, it provides several advantages:

* Each cherry picked commit references both the commit ID in the main branch and
  the GitHub PR number, which allows for easy navigation in the git history.

* By making changes to the "sycl-xxxx" branch via PRs, GitHub can automatically
  create release notes for the next update revision of the specification.
  If we had instead merged the commit manually, we would lose this ability.

After cherry picking PRs from "main" to "sycl-xxxx", it's useful to compare the
two branches and check that there are no unexpected differences:

```
$ git diff sycl-xxxx main
```


## Publishing an update revision

The working group normally accumulates a number of "clarification" PRs in the
SYCL-Docs repository before publishing them as an update revision of the current
specification.
When the working group decides it is time to publish an update revision, we
follow this process.

As noted above, the currently published major version may either correspond to
the "main" branch or to the "sycl-xxxx" branch, depending on the release cycle.
The instructions below refer to the branch that contains the currently published
major version as `<current>`.

* Go to our GitHub [Actions][1] tab and find the workflow run that merges the
  most recent PR to the `<current>` branch.
  Click the link, scroll to the bottom, and click the download icon for the
  "spec-outputs" build artifact.
  This ZIP file contains the specification that is ready to publish.

* Fork the [SYCL-Registry][2] repository and create a PR:

  * Unzip "spec-outputs.zip" into the directory "specs/sycl-xxxx".
    This should overwrite "sycl-xxxx.html" and "sycl-xxxx.pdf" with new
    versions.
  * Edit "index.php" to manually update the revision number and release date.
  * Do not merge this PR yet.

  You can use [this PR][3] as a model.

* Create a draft release at our GitHub [Releases][4] area:

  * Choose a release title of the form "Revision N" (where N is the revision
    number).
  * Under "Choose a tag" enter a new tag name of the form "SYCL-xxxx/final-revN"
    and click "Create new tag on publish".
  * Make sure the "Target" drop-down selects the `<current>` branch.
  * Create the release notes following the instructions below.
  * Upload the "spec-outputs.zip" file and attach it to the release.
  * Click "Save draft" to save the release as a draft.

* Create a PR to the "main" branch of the SYCL-Docs repository:

  * Edit "README.md" to change the release number in the badges.
  * Do not merge this PR yet.

  Note that this PR is created against the "main" branch even if you are making
  a release from the "sycl-xxxx" branch.
  You can use [this PR][5] as a model.

* When you are sure that you want to publish this release, do the following in
  quick succession and in this order:

  * Merge the PR to [SYCL-Registry][2].
  * Publish the draft release you created above.
  * Merge the PR to the "main" branch of SYCL-Docs.

  Note that the draft release must be published before Merging the second PR,
  otherwise the release tag will be created at the wrong commit.

* After publishing, you should also prepare for the next revision of the
  specification by making one more PR to the SYCL-Docs repository.
  This PR should be made to the `<current>` branch:

  * Edit "sycl\_version.txt", changing `SYCLREVISION` to the next revision
    number.

  You can use [this PR][6] as a model.

[1]: <https://github.com/KhronosGroup/SYCL-Docs/actions>
[2]: <https://github.com/KhronosGroup/SYCL-Registry>
[3]: <https://github.com/KhronosGroup/SYCL-Registry/pull/27>
[4]: <https://github.com/KhronosGroup/SYCL-Docs/releases>
[5]: <https://github.com/KhronosGroup/SYCL-Docs/pull/793>
[6]: <https://github.com/KhronosGroup/SYCL-Docs/pull/795>


## Generating release notes for an update release

The process for generating the release notes is different depending on whether
you are releasing from the "main" branch or from the "sycl-xxxx" branch.

If you are releasing from the "main" branch, you can simply click the button
"Generate release notes" when drafting the GitHub release.
This will generate the release notes automatically.

If you are releasing from the "sycl-xxxx" branch, you can start by clicking the
"Generate release notes" button, but the author information needs to be updated
manually.
The problem occurs because of the way we cherry pick PRs from the "main" branch
into the "sycl-xxxx" branch.
When GitHub automatically generates the release notes, it appears to get the
author information from the owner of the cherry picked PR.
Normally, the specification editor creates the cherry picked PRs, so GitHub
lists this person in the release notes rather than the owner of the original
PR.

We have not found a way to make cherry picks such that GitHub will automatically
show the correct author.
We have tried setting the "author" and "committer" fields of the git commit
before pushing it to the PR, but this doesn't help.
It appears that GitHub determines the author from the owner of the PR (not from
any field in the PR's commits), and GitHub does not provide any way to change
the owner of a PR.

Instead, we manually edit the release notes after they are automatically
generated.
There are two ways to do this.
One way is to open a second browser tab, create a temporary draft release from
the "main" branch, and click the "Generate release notes" button in this other
draft.
You can then compare entries in the two versions of the release notes, copying
the author information from the temporary release to the real one.
The other way to fix the author information is to click on each PR number in the
release notes, follow the link from the PR description "Cherry pick #NNN from
main", and get the author from the "#NNN" PR.


## Creating a KHR ratification package

When the working group approves a KHR extension, it merges a PR to the "main"
branch of the repository.
The next step is to submit the KHR to the Khronos board for ratification.
To do this, clone the following repository and follow the instructions in the
top-level README file.

https://gitlab.khronos.org/promoters/ratification-candidates

(Note that this repository is only accessible to Khronos members.)

Create a new directory `<root>/SYCL/<date>` for the ratification package.
When creating the `README.adoc` file, you can either start with the template
from the repository, or you can copy the `README.adoc` file from a previous
SYCL ratification package.

The package requires you to generate an HTML version of the KHR specification.
To do this, we simply use the generated HTML for the entire SYCL specification,
which includes the KHR in the appendices.
The `README.adoc` file lists the specific appendix and gives a link.
The best way to get the HTML is to download the CI build artifact from GitHub.
Go to our GitHub [Actions][1] tab and find the workflow run that merges the KHR
PR into the "main" branch.
Click the link, scroll to the bottom, and click the download icon for the
"spec-outputs" build artifact.
Unpack the downloaded ZIP file, and copy the "html" and "katex" directories to
`<root>/SYCL/<date>`.

Once the board ratifies the package, the KHR is eligible to be published.
Cherry pick the KHR's PR from the "main" branch to the "sycl-xxxx" branch,
following the instructions above under "Cherry pick strategy".
Since the KHR is an appendix in the main SYCL specification, the KHR will be
published whenever the working group decides to publish an update revision.


## Updating the Docker build image

Our CI process builds the HTML and PDF versions of the specification from
Asciidoc sources using a Docker image that contains all of the build tools.
This Docker image is maintained and published by the Khronos organization.
We choose to reference a specific version of this Docker image in our CI
configuration, so we can precisely track the tooling version that is used to
build our specification.
However, this means that we need to manually update that version whenever a new
Docker image is published.

In order to be notified about new versions, the specification editor should
register with https://docker-notify.com/ and watch for changes to
`khronosgroup/docker-images`.
This will cause you to get an email notification whenever a new Khronos Docker
image is published on Docker Hub.
We only care about changes to Docker images with tags named
`asciidoctor-spec.xxxx`, so you can ignore notifications for other tags.

When a new Docker image is published, create a PR like [this one][7] using the
Docker SHA labeled as "Manifest digest".

Before merging the PR, it's best to validate that the new tools don't cause any
unexpected problems by doing the following:

* Compare the HTML file "sycl-xxxx.html" that was created with the old Docker
  image with the file that was created with the new Docker image.
  This is a text file, so you can use the `diff` command.

* Compare the PDF file "sycl-xxxx.pdf" that was created with the old Docker image
  with the file that was created with the new Docker image.
  You can use https://www.draftable.com/compare to do this.

The date (and potentially the commit id) will be different.
If there are any other differences, you should determine whether they are an
expected result of the new build tools or if they indicate a problem that needs
to be fixed.

If you build the specification locally via `make docker-html docker-pdf`, then
you should also update your local copy of the Docker image.
The `Makefile` doesn't reference a specific version of the Docker image.
Instead, it references an "alias" with a tag named `asciidoctor-spec` (without
the `.xxxx` suffix).
The Khronos maintainers update this alias whenever there is a new version, so
you can update your local image via:

```
$ sudo docker pull khronosgroup/docker-images:asciidoctor-spec
```

And this will update your "alias" image with the latest version.

[7]: <https://github.com/KhronosGroup/SYCL-Docs/pull/595>


## Update the copyright date

At the beginning of each calendar year, we update the copyright dates in the
source files and also the copyright date of the published specification.
These can all be updated by running the following script from the root of the
repository:

```
$ bash ./adoc/scripts/update-copyright.sh
```

The script only updates files that have a copyright notice that matches a
certain pattern, and it prints the file names of any suspect notices to stdout.
If any file names are printed, examine them and update them manually.
(See the comments at the top of the script for details.)

Once you have finished, create a PR like [this one][8].

It's a good idea to manually examine the generated HTML and PDF specifications
afterwards to make sure the copyright date (at the start of the copyright
notice) is as you expect.

[8]: <https://github.com/KhronosGroup/SYCL-Docs/pull/786>
