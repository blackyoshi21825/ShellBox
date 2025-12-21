#!/bin/bash

# Check for flags from ShellBox
VERBOSE=${SB_VERBOSE:-0}
QUIET=${SB_QUIET:-0}
DEBUG=${SB_DEBUG:-0}
FAST=${SB_FAST:-0}

usage() {
    echo "Usage: $0 <domain> [wordlist]"
    echo "Examples:"
    echo "  $0 example.com"
    echo "  $0 example.com /usr/share/wordlists/subdomains.txt"
    exit 1
}

if [ $# -lt 1 ]; then
    usage
fi

domain=$1
wordlist=${2:-}

# Default subdomain list
default_subs="www mail ftp admin test dev staging api blog shop forum support help docs wiki cdn assets static images js css"

if [ "$QUIET" != "1" ]; then
    echo "Enumerating subdomains for: $domain"
    echo "----------------------------------------"
fi

# Use provided wordlist or default list
if [ -n "$wordlist" ] && [ -f "$wordlist" ]; then
    [ "$QUIET" != "1" ] && echo "Using wordlist: $wordlist"
    subs=$(cat "$wordlist")
else
    [ "$QUIET" != "1" ] && echo "Using default subdomain list"
    subs=$default_subs
fi

found=0
for sub in $subs; do
    subdomain="$sub.$domain"
    
    [ "$DEBUG" = "1" ] && echo "Checking: $subdomain"
    
    if nslookup "$subdomain" >/dev/null 2>&1; then
        ip=$(nslookup "$subdomain" | grep -A1 "Name:" | tail -1 | awk '{print $2}')
        if [ "$VERBOSE" = "1" ]; then
            echo "FOUND: $subdomain -> $ip"
        else
            echo "FOUND: $subdomain"
        fi
        ((found++))
    fi
    
    # Add delay if not in fast mode
    [ "$FAST" != "1" ] && sleep 0.1
done

if [ "$QUIET" != "1" ]; then
    echo "----------------------------------------"
    echo "Found $found subdomains"
fi