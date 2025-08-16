#!/bin/bash
# Batch rename files with a pattern

DIR="$1"
PATTERN="$2"
REPLACE="$3"
if [ -z "$DIR" ] || [ -z "$PATTERN" ] || [ -z "$REPLACE" ]; then
  echo "Usage: $0 <dir> <pattern> <replace>"
  exit 1
fi
for f in "$DIR"/*$PATTERN*; do
  mv "$f" "${f//$PATTERN/$REPLACE}"
done
echo "Renamed files in $DIR."
