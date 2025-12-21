#!/bin/bash

usage() {
    echo "Usage: $0 <host> <port> [timeout]"
    echo "Examples:"
    echo "  $0 example.com 80"
    echo "  $0 192.168.1.1 22 5"
    echo "  $0 localhost 3306"
    exit 1
}

if [ $# -lt 2 ]; then
    usage
fi

host=$1
port=$2
timeout=${3:-5}

echo "Banner grabbing from $host:$port"
echo "----------------------------------------"

# Try different methods based on port
case $port in
    21)  # FTP
        echo "Attempting FTP banner grab..."
        timeout $timeout telnet "$host" "$port" 2>/dev/null | head -5
        ;;
    22)  # SSH
        echo "Attempting SSH banner grab..."
        timeout $timeout ssh -o ConnectTimeout=$timeout "$host" 2>&1 | head -3
        ;;
    25|587)  # SMTP
        echo "Attempting SMTP banner grab..."
        echo "QUIT" | timeout $timeout telnet "$host" "$port" 2>/dev/null | head -5
        ;;
    53)  # DNS
        echo "Attempting DNS version query..."
        dig @"$host" version.bind chaos txt 2>/dev/null | grep -A1 "ANSWER SECTION"
        ;;
    80|8080)  # HTTP
        echo "Attempting HTTP banner grab..."
        curl -I -s --connect-timeout $timeout "http://$host:$port/" | head -10
        ;;
    110)  # POP3
        echo "Attempting POP3 banner grab..."
        echo "QUIT" | timeout $timeout telnet "$host" "$port" 2>/dev/null | head -3
        ;;
    143)  # IMAP
        echo "Attempting IMAP banner grab..."
        echo "a001 LOGOUT" | timeout $timeout telnet "$host" "$port" 2>/dev/null | head -5
        ;;
    443)  # HTTPS
        echo "Attempting HTTPS banner grab..."
        curl -I -s --connect-timeout $timeout "https://$host:$port/" | head -10
        ;;
    993|995)  # IMAPS/POP3S
        echo "Attempting SSL banner grab..."
        echo | timeout $timeout openssl s_client -connect "$host:$port" 2>/dev/null | head -20
        ;;
    3306)  # MySQL
        echo "Attempting MySQL banner grab..."
        timeout $timeout telnet "$host" "$port" 2>/dev/null | head -3
        ;;
    *)  # Generic
        echo "Attempting generic banner grab..."
        if command -v nc >/dev/null; then
            echo | timeout $timeout nc "$host" "$port" 2>/dev/null | head -10
        else
            timeout $timeout telnet "$host" "$port" 2>/dev/null | head -10
        fi
        ;;
esac