#!/bin/bash

usage() {
    echo "Usage: $0 [interface]"
    echo "Examples:"
    echo "  $0"
    echo "  $0 wlan0"
    exit 1
}

interface=${1:-}

echo "WiFi Network Scanner"
echo "----------------------------------------"

# Auto-detect wireless interface if not provided
if [ -z "$interface" ]; then
    if command -v iwconfig >/dev/null; then
        interface=$(iwconfig 2>/dev/null | grep -o '^[a-zA-Z0-9]*' | head -1)
    elif [ -d /sys/class/net ]; then
        interface=$(ls /sys/class/net/ | grep -E '^(wlan|wlp|wifi)' | head -1)
    fi
    
    if [ -z "$interface" ]; then
        echo "No wireless interface found. Please specify one."
        echo "Available interfaces:"
        if command -v ip >/dev/null; then
            ip link show | grep -E '^[0-9]+:' | cut -d: -f2 | tr -d ' '
        else
            ls /sys/class/net/ 2>/dev/null || echo "Unable to list interfaces"
        fi
        exit 1
    fi
fi

echo "Using interface: $interface"
echo

# Check if interface exists
if [ ! -d "/sys/class/net/$interface" ]; then
    echo "Interface $interface not found"
    exit 1
fi

# Scan for networks
if command -v iwlist >/dev/null; then
    echo "Scanning for WiFi networks..."
    sudo iwlist "$interface" scan 2>/dev/null | grep -E "(ESSID|Quality|Encryption)" | \
    sed 's/^[ \t]*//' | \
    awk '
    /ESSID/ { essid = $0; gsub(/ESSID:/, "", essid); gsub(/"/, "", essid) }
    /Quality/ { quality = $0 }
    /Encryption/ { 
        encryption = $0; 
        if (essid != "\"\"" && essid != "") {
            printf "%-30s %s %s\n", essid, quality, encryption
        }
    }'
elif command -v nmcli >/dev/null; then
    echo "Scanning for WiFi networks..."
    nmcli dev wifi list
else
    echo "No suitable WiFi scanning tool found (iwlist or nmcli required)"
    exit 1
fi