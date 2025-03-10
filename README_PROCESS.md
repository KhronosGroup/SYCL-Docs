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

  **TODO:** It appears that the GitHub automatically-generated release notes do
  not show the correct author for these cherry-picked PRs.
  This author is displayed as the author of the person who creates the cherry
  picked PR, which is normally the specification editor.
  I tried setting the "author" and "committer" fields of the git commit before
  it is pushed to the PR, but this doesn't help.
  I think GitHub determines the author from the owner of the PR (not from any
  field in the commit), and GitHub does not provide a way to change the owner of
  a PR.

After cherry picking PRs from "main" to "sycl-xxxx", it's useful to compare the
two branches and check that there are no unexpected differences:

```
$ git diff sycl-xxxx main
```


## Publishing an update revision

**TODO:** These are my notes from publishing SYCL 2020 revision 9.
We should check this process again when publishing revision 10 to make sure they
are accurate.

The working group normally accumulates a number of "clarification" PRs in this
GitHub repository before publishing them as an update revision of the current
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

* Fork the following repository and create a PR:

  https://github.com/KhronosGroup/SYCL-Registry

  * Unzip "spec-outputs.zip" into the directory "specs/sycl-xxxx".
    This should overwrite "sycl-xxxx.html" and "sycl-xxxx.pdf" with new
    versions.
  * Edit "index.php" to manually update the revision number and release date.
  * Do not merge this PR yet.

  You can use [this PR][2] as a model.

* Create a draft release at our GitHub [Releases][3] area:

  * Choose a release title of the form "Release N" (where N is the revision
    number).
  * Under "Choose a tag" enter a new tag name of the form "SYCL-xxxx/final-revN"
    and click "Create new tag on publish".
  * Make sure the "Target" drop-down selects the `<current>` branch.
  * Click "Generate release notes" to automatically generate release notes for
    this release.
  * Upload the "spec-outputs.zip" file and attach it to the release.
  * Click "Save draft" to save the release as a draft.

* Create a PR to the `<current>` branch of our GitHub repository with the
  following:

  * Edit "README.md" to change the release number in the badges.
  * Edit "sycl\_version.txt", changing `SYCLREVISION` to the next revision
    number.
    This will be the *next* revision number after the one you are publishing
    now.
  * Do not merge this PR yet.

  You can use [this PR][4] as a model.

* When you are sure that you want to publish this release, do the following in
  quick succession and in this order:

  * Merge the PR to https://github.com/KhronosGroup/SYCL-Registry
  * Publish the draft release you created above
  * Merge the PR to the `<current>` branch

  Note that the draft release must be published before Merging the second PR,
  otherwise the release tag will be created at the wrong commit.

[1]: <https://github.com/KhronosGroup/SYCL-Docs/actions>
[2]: <https://github.com/KhronosGroup/SYCL-Registry/pull/26>
[3]: <https://github.com/KhronosGroup/SYCL-Docs/releases>
[4]: <https://github.com/KhronosGroup/SYCL-Docs/pull/605>


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
