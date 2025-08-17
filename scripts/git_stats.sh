#!/bin/bash

if ! git rev-parse --git-dir > /dev/null 2>&1; then
    echo "Not a git repository"
    exit 1
fi

echo "=== Git Repository Statistics ==="
echo

echo "Repository: $(basename $(git rev-parse --show-toplevel))"
echo "Branch: $(git branch --show-current)"
echo "Total commits: $(git rev-list --all --count)"
echo "Contributors: $(git shortlog -sn | wc -l)"
echo

echo "=== Top Contributors ==="
git shortlog -sn | head -5

echo
echo "=== Recent Activity ==="
echo "Commits this week: $(git rev-list --since='1 week ago' --count HEAD)"
echo "Commits this month: $(git rev-list --since='1 month ago' --count HEAD)"

echo
echo "=== File Statistics ==="
echo "Total files tracked: $(git ls-files | wc -l)"
echo "Largest files:"
git ls-files | xargs ls -la | sort -k5 -nr | head -3 | awk '{print $5 " bytes - " $9}'