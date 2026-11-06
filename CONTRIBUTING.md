<!--
SPDX-FileCopyrightText: 2026 The Khronos Group, Inc.
SPDX-License-Identifier: CC-BY-4.0
-->

# Contributing

## Contributor License Agreement (CLA)

When you propose a pull request on this repository you must execute a Khronos
[Mixed Repository Contributor License Agreement
(CLA)](https://www.khronos.org/cla/KhronosGroup/SYCL-Docs), to confirm
you own your work and are granting Khronos the necessary permissions to
redistribute it under our licenses.

## Pull request approval requirements

### Who can submit

Anyone can open a pull request, provided they have signed the CLA described in
[Contributor License Agreement (CLA)](#contributor-license-agreement-cla).
A bot will prompt you to sign it when you open your first PR.

A pull request may be merged once CI passes and it meets the criteria below.

### Who can approve

Only GitHub "Approve" reviews from **SYCL Working Group (WG) members** count
toward these requirements.

### Specification changes

* At least **2 approving reviews** from SYCL WG members representing **two
  different companies**, neither of which is the PR author's company.

### KHR extensions

* **2 implementers:** one who has implemented the extension (this may be the PR
  author) and another implementer who agrees with the extension.
* At least **2 approving reviews** from SYCL WG members representing **two
  different companies**, neither of which is the PR author's company.
  Implementers may also serve as these reviewers.

### Editorial changes

Changes that do not alter the meaning of the specification (e.g., typos,
formatting, broken links, CI or build updates) may be merged by the
**Spec Editor** at their discretion.

### Conformance tests (SYCL-CTS)

Each change to the specification must be accompanied by a corresponding change
to the [SYCL-CTS](https://github.com/KhronosGroup/SYCL-CTS) when the change
affects behavior.

A non-editorial specification PR is not merged until the corresponding SYCL-CTS
PR has been approved.

For reference, PRs to the SYCL-CTS repository require at least **1 approving
review** from a SYCL WG member who works for a different company than the PR
author.

### Who merges

* **Specification PRs** are merged by the **Spec Editor**.
* **SYCL-CTS PRs** are merged by the **SYCL Chair**.

## AI-Assisted Contributions

By submitting a Contribution to this repository, you additionally represent
that, to the extent any of Your Contributions were developed with the assistance
of artificial intelligence tools or AI-generated code, You have exercised
sufficient review, judgment, and creative direction over such tools and
resulting material to reasonably consider it Your original creation, and You are
not aware of any third-party license, intellectual property claim, or other
restriction arising from such use that is associated with any part of Your
Contribution or use thereof.
