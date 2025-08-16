#!/bin/bash
# Move files by type or date

SRC="$1"
DEST="$2"
TYPE="$3"
if [ -z "$SRC" ] || [ -z "$DEST" ] || [ -z "$TYPE" ]; then
  echo "Usage: $0 <source_dir> <dest_dir> <file_extension>"
  exit 1
fi
find "$SRC" -type f -name "*.$TYPE" -exec mv {} "$DEST" \;
echo "Moved all .$TYPE files from $SRC to $DEST."
