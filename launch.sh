#!/bin/bash
echo "Building Shell Box..."
make shellbox
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi
echo
echo "Starting Shell Box Terminal..."
echo
make shellbox