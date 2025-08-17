#!/bin/bash
# Display CPU, memory, and OS info

echo "CPU Info:"
if [[ "$OSTYPE" == "darwin"* ]]; then
    sysctl -n machdep.cpu.brand_string
    echo "Cores: $(sysctl -n hw.ncpu)"
else
    uname -p
    lscpu || echo "lscpu not available"
fi

echo -e "\nMemory Info:"
if [[ "$OSTYPE" == "darwin"* ]]; then
    echo "Total: $(echo "$(sysctl -n hw.memsize) / 1024 / 1024 / 1024" | bc) GB"
    vm_stat | head -5
else
    free -h || echo "free not available"
fi

echo -e "\nOS Info:"
uname -a