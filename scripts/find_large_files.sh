#!/bin/bash
# List largest files in a directory

du -ah "$1" | sort -rh | head -n 10
