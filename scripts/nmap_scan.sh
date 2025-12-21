#!/bin/bash

# Check for flags from ShellBox
VERBOSE=${SB_VERBOSE:-0}
QUIET=${SB_QUIET:-0}
DEBUG=${SB_DEBUG:-0}
STEALTH=${SB_STEALTH:-0}
FAST=${SB_FAST:-0}
AGGRESSIVE=${SB_AGGRESSIVE:-0}

usage() {
    echo "Usage: $0 <target> [scan_type]"
    echo "Scan types:"
    echo "  quick    - Quick port scan (default)"
    echo "  stealth  - SYN stealth scan"
    echo "  service  - Service version detection"
    echo "  os       - OS detection"
    echo "  vuln     - Vulnerability scan"
    echo "Examples:"
    echo "  $0 192.168.1.1"
    echo "  $0 192.168.1.0/24 stealth"
    exit 1
}

if [ $# -lt 1 ]; then
    usage
fi

target=$1
scan_type=${2:-quick}

if ! command -v nmap >/dev/null; then
    echo "Error: nmap not installed. Install with:"
    echo "  Ubuntu/Debian: sudo apt install nmap"
    echo "  CentOS/RHEL: sudo yum install nmap"
    echo "  macOS: brew install nmap"
    exit 1
fi

# Apply flags to modify behavior
if [ "$FAST" = "1" ]; then
    scan_type="quick"
fi

if [ "$STEALTH" = "1" ] && [ "$scan_type" != "quick" ]; then
    scan_type="stealth"
fi

NMAP_OPTS=""
if [ "$VERBOSE" = "1" ]; then
    NMAP_OPTS="$NMAP_OPTS -v"
fi

if [ "$AGGRESSIVE" = "1" ]; then
    NMAP_OPTS="$NMAP_OPTS -T4"
else
    NMAP_OPTS="$NMAP_OPTS -T3"
fi

if [ "$QUIET" != "1" ]; then
    echo "Scanning target: $target"
    echo "Scan type: $scan_type"
    [ "$DEBUG" = "1" ] && echo "Nmap options: $NMAP_OPTS"
    echo "----------------------------------------"
fi

case $scan_type in
    quick)
        nmap $NMAP_OPTS -F "$target"
        ;;
    stealth)
        nmap $NMAP_OPTS -sS "$target"
        ;;
    service)
        nmap $NMAP_OPTS -sV "$target"
        ;;
    os)
        nmap $NMAP_OPTS -O "$target"
        ;;
    vuln)
        nmap $NMAP_OPTS --script vuln "$target"
        ;;
    *)
        echo "Unknown scan type: $scan_type"
        usage
        ;;
esac