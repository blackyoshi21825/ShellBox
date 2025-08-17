#!/bin/bash
# Show disk usage summary

if [[ "$OSTYPE" == "darwin"* ]]; then
    du -h -d 1
else
    du -h --max-depth=1
fi
