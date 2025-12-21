#!/bin/bash

usage() {
    echo "Usage: $0 <hash> <type> [wordlist]"
    echo "Hash types: md5, sha1, sha256"
    echo "Examples:"
    echo "  $0 5d41402abc4b2a76b9719d911017c592 md5"
    echo "  $0 aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d sha1"
    exit 1
}

if [ $# -lt 2 ]; then
    usage
fi

hash_value=$1
hash_type=$2
wordlist=${3:-}

# Default wordlist
default_words="password 123456 admin root test guest user hello world qwerty abc123 password123 admin123"

echo "Attempting to crack $hash_type hash: $hash_value"
echo "----------------------------------------"

# Use provided wordlist or default list
if [ -n "$wordlist" ] && [ -f "$wordlist" ]; then
    echo "Using wordlist: $wordlist"
    words=$(cat "$wordlist")
else
    echo "Using default password list"
    words=$default_words
fi

found=false
for word in $words; do
    case $hash_type in
        md5)
            computed=$(echo -n "$word" | md5sum | cut -d' ' -f1)
            ;;
        sha1)
            computed=$(echo -n "$word" | sha1sum | cut -d' ' -f1)
            ;;
        sha256)
            computed=$(echo -n "$word" | sha256sum | cut -d' ' -f1)
            ;;
        *)
            echo "Unsupported hash type: $hash_type"
            exit 1
            ;;
    esac
    
    if [ "$computed" = "$hash_value" ]; then
        echo "CRACKED! Password: $word"
        found=true
        break
    fi
done

if [ "$found" = false ]; then
    echo "Hash not cracked with provided wordlist"
fi