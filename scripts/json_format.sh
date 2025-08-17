#!/bin/bash

usage() {
    echo "Usage: $0 [format|validate|minify] [file|stdin]"
    echo "Examples:"
    echo "  $0 format data.json"
    echo "  echo '{\"key\":\"value\"}' | $0 format"
    echo "  $0 validate data.json"
    exit 1
}

action=${1:-format}
input=$2

process_json() {
    case "$action" in
        "format")
            if command -v python3 >/dev/null; then
                python3 -m json.tool
            elif command -v jq >/dev/null; then
                jq .
            else
                echo "Python3 or jq required for JSON formatting"
                exit 1
            fi
            ;;
        "validate")
            if command -v python3 >/dev/null; then
                python3 -c "import json, sys; json.load(sys.stdin); print('Valid JSON')" 2>/dev/null || echo "Invalid JSON"
            else
                echo "Python3 required for JSON validation"
                exit 1
            fi
            ;;
        "minify")
            if command -v python3 >/dev/null; then
                python3 -c "import json, sys; print(json.dumps(json.load(sys.stdin), separators=(',', ':')))"
            else
                echo "Python3 required for JSON minification"
                exit 1
            fi
            ;;
        *)
            usage
            ;;
    esac
}

if [ -n "$input" ] && [ -f "$input" ]; then
    process_json < "$input"
elif [ -t 0 ]; then
    usage
else
    process_json
fi