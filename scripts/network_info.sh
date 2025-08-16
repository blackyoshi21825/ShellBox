#!/bin/bash
# Show IP, MAC, and network status

echo "IP Address:"
ip addr show || ifconfig
echo "\nMAC Address:"
ip link show || ifconfig -a | grep -i ether
echo "\nNetwork Status:"
ping -c 2 8.8.8.8
