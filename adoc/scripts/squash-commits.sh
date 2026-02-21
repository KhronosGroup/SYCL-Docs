#!/bin/bash
# Copyright (c) 2024-2026 The Khronos Group, Inc.
# SPDX-License-Identifier: Apache-2.0
#
# squash-commits.sh [--create] <branch>
#
#
# NOTE: We don't use this script anymore, but keeping it around in case it
# becomes useful again someday.  We originally wrote this script because
# another team wanted a linear history of squashed commits to our repo, rather
# than the merged commit history that we currently maintain.
#
# Script that maintains a branch of squashed commits, where each commit
# represents one PR that was merged into <branch>.  To use this script, first
# create a new branch <squashed> that will hold the squashed commit history of
# some target branch <branch>.  The squashed branch should start somewhere on
# the first parent chain of <branch>:
#
#   $ git branch <squashed> <start-point>
#
# then run:
#
#   $ squash-commits.sh --create <branch>
#
# This will create squashed commits for each PR merged into <branch> since
# <start-point>.  Thereafter, you may periodically run these commands to add
# new squashed commits for additional PRs that have been merged into <branch>:
#
#   $ git checkout <squashed>
#   $ squash-commits.sh <branch>

start_point=""
if [ "$1" == "--create" ]; then
  start_point=$(git rev-parse HEAD)
  shift
fi
if [ "$#" -eq 1 ]; then
  branch=$1
else
  echo "Usage: squash-commits [--create] <branch>"
  exit 1
fi

if ! $(git show-ref --verify --quiet refs/heads/$branch); then
  echo "There is no branch named $branch."
  exit 1
fi

if [ -z "$start_point" ]; then
  # Extract the original commit hash from the cherry-pick message (it's the
  # last word of the commit message)
  start_point=$(git log -1 --format=%B HEAD | grep "cherry picked from commit" |
    awk '{print $NF}' | tr -d ')')

  # Check if the original commit hash was extracted
  if [ -z "$start_point" ]; then
    echo "Failed to find last squashed commit ID in <squashed> branch."
    exit 1
  fi
fi

# Get all commits after the start commit on the target branch (first-parent only)
commits_to_cherry_pick=$(git log --first-parent --format=%H --reverse $start_point..$branch)

# Check if there are any commits to cherry-pick
if [ -z "$commits_to_cherry_pick" ]; then
  echo "No commits to cherry-pick from $branch after $start_point."
  exit 0
fi

# Cherry-pick all commits (merge or non-merge) with -m 1 and -x to include the
# cherry-pick message
echo "Cherry-picking all commits from $branch after $start_point..."
git cherry-pick -m 1 -x $commits_to_cherry_pick

# Check if the cherry-pick succeeded
if [ $? -ne 0 ]; then
  echo "Cherry-pick failed. Resolve conflicts, then run 'git cherry-pick --continue' to finish."
  exit 1
fi

echo "Successfully cherry-picked all relevant commits from $branch."
