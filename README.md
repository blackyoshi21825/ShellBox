```
 ____  _          _ _ ____            
/ ___|| |__   ___| | | __ )  _____  __
\___ \| '_ \ / _ \ | |  _ \ / _ \ \/ /
 ___) | | | |  __/ | | |_) | (_) >  <
|____/|_| |_|\___|_|_|____/ \___/_/\_\

```

# Shell Box

🚀 A cross-platform utility suite for Mac, Windows, and Linux, combining Bash/shell scripts and C programs. Shell Box provides data management, system insights, and other helpful tools for command-line users.

## ✨ Features

- 🖥️ **Custom Terminal Interface** - Beautiful interactive shell with colored output
- 🔧 **System Tools** - CPU info, memory stats, disk usage, network monitoring, uptime
- 📁 **File Operations** - Search, copy, hash, duplicate detection, tree operations
- 🌐 **Network Utilities** - Port scanning, connectivity checks, network info
- 📊 **Development Tools** - Git stats, JSON formatting, encoding utilities
- 🔍 **Text Processing** - Grep with regex support
- 💾 **System Analysis** - Process monitoring, disk usage analysis
- 🔒 **Security Tools** - Network scanning, subdomain enumeration, directory brute force, hash cracking

## 🚀 Quick Start

### Launch Shell Box Terminal

**Windows:**
```cmd
launch.bat
```

**Linux/WSL/Mac:**
```bash
chmod +x launch.sh
./launch.sh
```

### Manual Build & Run
```bash
make shellbox
./bin/shellbox
```

## 📁 Structure
- `bin/`: Compiled C binaries
- `scripts/`: Bash/shell scripts  
- `src/`: C source code
- `launch.*`: Quick start scripts

## 📋 Available Commands

Once in the ShellBox terminal, use these commands:

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

## 🚩 Using Flags

Flags modify the behavior of commands. Toggle them on/off with the `!` prefix:

```bash
shellbox> !verbose      # Enable verbose output
shellbox> !stealth      # Enable stealth mode
shellbox> nmap-scan 192.168.1.1  # Runs with verbose + stealth
shellbox> !status       # Check which flags are active
shellbox> !reset        # Turn off all flags
```

**Flag Combinations:**
- `!fast + !quiet` - Quick scans with minimal output
- `!verbose + !debug` - Maximum detail for troubleshooting
- `!stealth + !quiet` - Silent reconnaissance
- `!aggressive + !verbose` - Fast aggressive scans with full output

## 🛠️ Traditional Usage

### Setup PATH (Optional)
**Windows:**
```cmd
setup.bat
```

**WSL/Linux:**
```bash
chmod +x setup.sh
./setup.sh
```

### Build Individual Tools
```bash
make all          # Build everything
make sb-cpuinfo   # Build & run CPU info
make sb-meminfo   # Build & run memory info
```

## 🔧 Extending
Add new scripts or C programs to the respective folders. Update the Makefile as needed.

## 📖 Documentation
See [COMMANDS.md](COMMANDS.md) for detailed command reference.
See [SECURITY.md](SECURITY.md) for security tools guide and ethical hacking workflows.

## ⚠️ Legal Notice
Security tools are for ETHICAL HACKING and AUTHORIZED TESTING ONLY. Always obtain proper authorization before testing systems you do not own. Unauthorized access is illegal.
