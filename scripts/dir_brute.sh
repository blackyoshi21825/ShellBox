#!/bin/bash

usage() {
    echo "Usage: $0 <url> [wordlist]"
    echo "Examples:"
    echo "  $0 http://example.com"
    echo "  $0 https://example.com /usr/share/wordlists/dirb/common.txt"
    exit 1
}

if [ $# -lt 1 ]; then
    usage
fi

url=$1
wordlist=${2:-}

# Remove trailing slash
url=${url%/}

# Default directory list
default_dirs="admin login wp-admin dashboard panel config backup test dev staging api docs help support uploads images css js assets static robots.txt sitemap.xml .htaccess"

echo "Directory brute force for: $url"
echo "----------------------------------------"

# Use provided wordlist or default list
if [ -n "$wordlist" ] && [ -f "$wordlist" ]; then
    echo "Using wordlist: $wordlist"
    dirs=$(cat "$wordlist")
else
    echo "Using default directory list"
    dirs=$default_dirs
fi

found=0
for dir in $dirs; do
    target_url="$url/$dir"
    response=$(curl -s -o /dev/null -w "%{http_code}" "$target_url" --connect-timeout 5)
    
    case $response in
        200)
            echo "FOUND [200]: $target_url"
            ((found++))
            ;;
        301|302)
            echo "REDIRECT [$response]: $target_url"
            ((found++))
            ;;
        403)
            echo "FORBIDDEN [403]: $target_url"
            ((found++))
            ;;
    esac
done

echo "----------------------------------------"
echo "Found $found directories/files"