#!/bin/bash
# Sync two directories

SRC="$1"
DEST="$2"
if [ -z "$SRC" ] || [ -z "$DEST" ]; then
  echo "Usage: $0 <source_dir> <dest_dir>"
  exit 1
fi
rsync -av --delete "$SRC/" "$DEST/"
echo "Synced $SRC to $DEST."
