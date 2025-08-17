#!/bin/bash
# Show IP, MAC, and network status

echo "IP Address:"
if [[ "$OSTYPE" == "darwin"* ]]; then
    ifconfig | grep "inet " | grep -v 127.0.0.1
else
    ip addr show || ifconfig
fi

echo -e "\nMAC Address:"
if [[ "$OSTYPE" == "darwin"* ]]; then
    ifconfig | grep ether
else
    ip link show || ifconfig -a | grep -i ether
fi

echo -e "\nNetwork Status:"
ping -c 2 8.8.8.8