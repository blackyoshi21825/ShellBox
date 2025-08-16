#!/bin/bash
# Remove empty directories

find "$1" -type d -empty -delete
echo "Deleted empty directories in $1."
