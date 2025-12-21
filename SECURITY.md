# ShellBox Security Tools Guide

## ⚠️ Legal Disclaimer
These tools are for ETHICAL HACKING and AUTHORIZED TESTING ONLY. Always obtain proper authorization before testing any systems you do not own. Unauthorized access to computer systems is illegal.

## Security Tools Overview

### 1. Network Scanning (nmap-scan)
Scan networks and hosts for open ports and services.

**Usage in ShellBox Terminal:**
```
nmap-scan
```

**Examples:**
- Quick scan: `192.168.1.1 quick`
- Stealth scan: `192.168.1.0/24 stealth`
- Service detection: `example.com service`
- OS detection: `192.168.1.1 os`
- Vulnerability scan: `192.168.1.1 vuln`

**Requirements:** nmap must be installed

---

### 2. Subdomain Enumeration (subdomain-enum)
Discover subdomains of a target domain.

**Usage in ShellBox Terminal:**
```
subdomain-enum
```

**Examples:**
- Basic scan: `example.com`
- With wordlist: `example.com /path/to/wordlist.txt`

**Default subdomains checked:**
www, mail, ftp, admin, test, dev, staging, api, blog, shop, forum, support, help, docs, wiki, cdn, assets, static, images, js, css

---

### 3. Directory Brute Force (dir-brute)
Discover hidden directories and files on web servers.

**Usage in ShellBox Terminal:**
```
dir-brute
```

**Examples:**
- Basic scan: `http://example.com`
- With wordlist: `https://example.com /usr/share/wordlists/dirb/common.txt`

**Default directories checked:**
admin, login, wp-admin, dashboard, panel, config, backup, test, dev, staging, api, docs, help, support, uploads, images, css, js, assets, static, robots.txt, sitemap.xml, .htaccess

**Response codes:**
- 200: Found (accessible)
- 301/302: Redirect
- 403: Forbidden (exists but no access)

---

### 4. Hash Cracking (hash-crack)
Crack password hashes using wordlists.

**Usage in ShellBox Terminal:**
```
hash-crack
```

**Examples:**
- MD5: `5d41402abc4b2a76b9719d911017c592 md5`
- SHA1: `aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d sha1`
- With wordlist: `hash_value sha256 /path/to/rockyou.txt`

**Supported hash types:**
- md5
- sha1
- sha256

---

### 5. WiFi Scanner (wifi-scan)
Scan for available WiFi networks.

**Usage in ShellBox Terminal:**
```
wifi-scan
```

**Examples:**
- Auto-detect interface: `wifi-scan`
- Specific interface: `wlan0`

**Requirements:** iwlist or nmcli, may require sudo

---

### 6. Banner Grabbing (banner-grab)
Grab service banners to identify software versions.

**Usage in ShellBox Terminal:**
```
banner-grab
```

**Examples:**
- HTTP: `example.com 80`
- SSH: `192.168.1.1 22`
- MySQL: `localhost 3306`
- Custom timeout: `example.com 443 10`

**Supported services:**
- FTP (21)
- SSH (22)
- SMTP (25, 587)
- DNS (53)
- HTTP (80, 8080)
- POP3 (110)
- IMAP (143)
- HTTPS (443)
- IMAPS/POP3S (993, 995)
- MySQL (3306)

---

## Ethical Hacking Workflow

### 1. Reconnaissance Phase
```
# Scan target network
nmap-scan 192.168.1.0/24 quick

# Enumerate subdomains
subdomain-enum target.com

# Grab service banners
banner-grab target.com 80
banner-grab target.com 22
```

### 2. Scanning Phase
```
# Detailed service scan
nmap-scan target.com service

# OS detection
nmap-scan target.com os

# Directory enumeration
dir-brute http://target.com
```

### 3. Vulnerability Assessment
```
# Vulnerability scan
nmap-scan target.com vuln

# Check for common misconfigurations
dir-brute http://target.com
```

### 4. Password Cracking
```
# Crack captured hashes
hash-crack <hash_value> md5 /path/to/wordlist.txt
```

---

## Best Practices

1. **Always get authorization** before testing any system
2. **Document everything** - keep logs of your testing
3. **Use VPN/proxy** when appropriate for privacy
4. **Rate limit** your scans to avoid DoS
5. **Respect robots.txt** and security.txt
6. **Report findings** responsibly to system owners
7. **Stay legal** - know your local laws regarding security testing

---

## Additional Resources

### Wordlists
- SecLists: https://github.com/danielmiessler/SecLists
- RockYou: Common password list
- DirBuster wordlists: /usr/share/wordlists/dirbuster/

### Learning Resources
- OWASP: https://owasp.org
- HackTheBox: https://hackthebox.eu
- TryHackMe: https://tryhackme.com
- PortSwigger Web Security Academy: https://portswigger.net/web-security

---

## Troubleshooting

### nmap-scan not working
```bash
# Install nmap
sudo apt install nmap        # Ubuntu/Debian
sudo yum install nmap        # CentOS/RHEL
brew install nmap            # macOS
```

### wifi-scan requires sudo
```bash
sudo ./bin/shellbox
# Then run: wifi-scan
```

### Permission denied errors
Some tools require elevated privileges. Run ShellBox with sudo if needed.
