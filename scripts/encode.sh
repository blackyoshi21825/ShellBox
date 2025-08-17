#!/bin/bash

usage() {
    echo "Usage: $0 <encode|decode> <base64|url> [text|file]"
    echo "Examples:"
    echo "  $0 encode base64 \"hello world\""
    echo "  $0 decode base64 aGVsbG8gd29ybGQ="
    echo "  $0 encode url \"hello world\""
    exit 1
}

if [ $# -lt 3 ]; then
    usage
fi

action=$1
type=$2
input=$3

case "$action" in
    "encode")
        case "$type" in
            "base64")
                if [ -f "$input" ]; then
                    base64 < "$input"
                else
                    echo -n "$input" | base64
                fi
                ;;
            "url")
                if command -v python3 >/dev/null; then
                    python3 -c "import urllib.parse; print(urllib.parse.quote('$input'))"
                else
                    echo "Python3 required for URL encoding"
                    exit 1
                fi
                ;;
            *)
                echo "Unsupported encoding type: $type"
                exit 1
                ;;
        esac
        ;;
    "decode")
        case "$type" in
            "base64")
                echo "$input" | base64 -d
                ;;
            "url")
                if command -v python3 >/dev/null; then
                    python3 -c "import urllib.parse; print(urllib.parse.unquote('$input'))"
                else
                    echo "Python3 required for URL decoding"
                    exit 1
                fi
                ;;
            *)
                echo "Unsupported decoding type: $type"
                exit 1
                ;;
        esac
        ;;
    *)
        usage
        ;;
esac