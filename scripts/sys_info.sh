#!/bin/bash
# Display CPU, memory, and OS info

echo "CPU Info:"
uname -p
lscpu || echo "lscpu not available"
echo "\nMemory Info:"
free -h || echo "free not available"
echo "\nOS Info:"
uname -a
