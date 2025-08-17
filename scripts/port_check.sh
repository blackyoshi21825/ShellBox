#!/bin/bash

usage() {
    echo "Usage: $0 <host> <port> [timeout]"
    echo "       $0 scan <host> <start_port> <end_port>"
    echo "Examples:"
    echo "  $0 google.com 80"
    echo "  $0 localhost 3000 5"
    echo "  $0 scan localhost 80 90"
    exit 1
}

check_port() {
    local host=$1
    local port=$2
    local timeout=${3:-3}
    
    if command -v nc >/dev/null; then
        nc -z -w$timeout "$host" "$port" 2>/dev/null
    elif command -v timeout >/dev/null; then
        timeout $timeout bash -c "</dev/tcp/$host/$port" 2>/dev/null
    else
        bash -c "</dev/tcp/$host/$port" 2>/dev/null
    fi
}

if [ $# -lt 2 ]; then
    usage
fi

if [ "$1" = "scan" ]; then
    if [ $# -lt 4 ]; then
        usage
    fi
    
    host=$2
    start_port=$3
    end_port=$4
    
    echo "Scanning ports $start_port-$end_port on $host..."
    
    for port in $(seq $start_port $end_port); do
        if check_port "$host" "$port" 1; then
            echo "Port $port: OPEN"
        fi
    done
else
    host=$1
    port=$2
    timeout=${3:-3}
    
    if check_port "$host" "$port" "$timeout"; then
        echo "Port $port on $host: OPEN"
        exit 0
    else
        echo "Port $port on $host: CLOSED"
        exit 1
    fi
fi