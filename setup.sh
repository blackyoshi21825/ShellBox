#!/bin/bash
# Add ShellBox bin directory to PATH
SHELLBOX_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export PATH="$SHELLBOX_DIR/bin:$PATH"
echo "ShellBox tools added to PATH for this session"
echo "Available commands: make sb-<command>"
bash