#!/bin/bash
# Simple backup utility

SRC="$1"
DEST="$2"
if [ -z "$SRC" ] || [ -z "$DEST" ]; then
  echo "Usage: $0 <source> <destination>"
  exit 1
fi
cp -r "$SRC" "$DEST"
echo "Backup complete."
