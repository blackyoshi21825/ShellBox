# Shell Box Commands

## ShellBox Terminal Commands

Once in the ShellBox terminal (`./bin/shellbox`), use these commands directly:

### System Information
- `ci` (cpuinfo) - Display CPU information
- `mi` (meminfo) - Display memory information
- `ns` (netstat) - Display network statistics
- `up` (uptime) - Display system uptime and load
- `di` (diskinfo) - Display disk usage and mount points
- `si` (sys-info) - Comprehensive system information

### File Operations
- `fs` (file-search) - Search for files
- `fi` (file-info) - Display detailed file information
- `fd` (find-duplicates) - Find duplicate files
- `ct` (copytree) - Copy directory trees
- `dt` (deltree) - Delete directory trees

### Text Processing
- `gr` (grep) - Search text patterns with regex support
- `ha` (hash) - Calculate file hashes (MD5, SHA256)

### System Tools
- `bk` (backup) - Backup files and directories
- `du` (disk-usage) - Display disk usage information
- `pl` (process-list) - List running processes
- `pc` (port-check) - Check port connectivity
- `ni` (network-info) - Display network information

### Development Tools
- `en` (encode) - Encode/decode text (base64, URL)
- `js` (json) - Format, validate, or minify JSON
- `gs` (git-stats) - Git repository statistics

### Security Tools
- `nm` (nmap-scan) - Network scanning with nmap (requires nmap)
- `se` (subdomain-enum) - Subdomain enumeration
- `db` (dir-brute) - Web directory brute force
- `hc` (hash-crack) - Hash cracking with wordlists
- `ws` (wifi-scan) - WiFi network scanner
- `bg` (banner-grab) - Service banner grabbing

### Terminal Commands
- `help` - Show available commands
- `clear` - Clear screen and show banner
- `exit` - Exit ShellBox

### Flags (start with !)
- `!verbose` - Enable verbose output for commands
- `!quiet` - Suppress non-essential output
- `!debug` - Enable debug mode with detailed logs
- `!stealth` - Use stealth mode for security tools
- `!fast` - Use fast/quick scan modes
- `!aggressive` - Use aggressive scanning (use with caution)
- `!reset` - Reset all flags to default
- `!status` - Show current flag status
- `!help` - Show flag help

---

## Traditional Make Commands

## Traditional Make Commands

### Build Commands
### Build All
```bash
make all
```
Builds all C programs and utilities.

### Clean
```bash
make clean
```
Removes all compiled binaries from the `bin/` directory.

## C Program Commands

### System Information
- `make sb-cpuinfo` - Display CPU information
- `make sb-meminfo` - Display memory information
- `make sb-netstat` - Display network statistics
- `make sb-uptime` - Display system uptime and load averages
- `make sb-diskinfo` - Display disk usage, filesystem types, and mount points

### File Operations
- `make sb-file-search` - Search for files
- `make sb-file-info` - Display file information
- `make sb-find-duplicates` - Find duplicate files
- `make sb-copytree` - Copy directory trees
- `make sb-deltree` - Delete directory trees

### Text Processing
- `make sb-grep` - Search text patterns in files with regex support

### Security & Hashing
- `make sb-hash FILE='filename' [TYPE='md5|sha256']` - Calculate file hashes

### Utilities
- `make sb-hello` - Hello world program

## Shell Script Commands

### File Management
- `make sb-backup` - Backup files and directories
- `make sb-move-files` - Move files based on criteria
- `make sb-rename-batch` - Batch rename files
- `make sb-sync-dirs` - Synchronize directories

### System Analysis
- `make sb-disk-usage` - Display disk usage information
- `make sb-folder-size` - Calculate folder sizes
- `make sb-find-large-files` - Find large files on system
- `make sb-delete-empty-dirs` - Remove empty directories

### System Information
- `make sb-sys-info` - Display system information
- `make sb-network-info` - Display network information
- `make sb-process-list` - List running processes

### Development Tools
- `make sb-encode ACTION='encode|decode' TYPE='base64|url' TEXT='text'` - Encode/decode text
- `make sb-json ACTION='format|validate|minify' [FILE='filename']` - JSON processing
- `make sb-git-stats` - Git repository statistics

### Network Tools
- `make sb-port-check HOST='hostname' PORT='port'` - Check port connectivity
- `make sb-port-check ACTION='scan' HOST='hostname' START='start_port' END='end_port'` - Port scanning

## Security Tools

### Network Scanning
- `make sb-nmap-scan TARGET='192.168.1.1' [TYPE='quick|stealth|service|os|vuln']` - Nmap network scanning
  - `quick` - Fast port scan (default)
  - `stealth` - SYN stealth scan
  - `service` - Service version detection
  - `os` - Operating system detection
  - `vuln` - Vulnerability scanning

### Reconnaissance
- `make sb-subdomain-enum DOMAIN='example.com' [WORDLIST='path/to/wordlist']` - Enumerate subdomains
- `make sb-dir-brute URL='http://example.com' [WORDLIST='path/to/wordlist']` - Web directory brute force
- `make sb-banner-grab HOST='hostname' PORT='port' [TIMEOUT='seconds']` - Grab service banners

### Password Cracking
- `make sb-hash-crack HASH='hash_value' TYPE='md5|sha1|sha256' [WORDLIST='path/to/wordlist']` - Crack password hashes

### Wireless
- `make sb-wifi-scan [INTERFACE='wlan0']` - Scan for WiFi networks