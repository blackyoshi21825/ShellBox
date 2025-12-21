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
- `cpuinfo` - Display CPU information
- `meminfo` - Display memory information  
- `netstat` - Display network statistics
- `uptime` - Display system uptime and load
- `diskinfo` - Display disk usage and mount points
- `sys-info` - Comprehensive system information

### File Operations
- `file-search` - Search for files
- `file-info` - Display detailed file information
- `find-duplicates` - Find duplicate files
- `copytree` - Copy directory trees
- `deltree` - Delete directory trees

### Text Processing
- `grep` - Search text patterns with regex support
- `hash` - Calculate file hashes (MD5, SHA256)

### System Tools
- `backup` - Backup files and directories
- `disk-usage` - Display disk usage information
- `process-list` - List running processes
- `port-check` - Check port connectivity
- `network-info` - Display network information

### Development Tools
- `encode` - Encode/decode text (base64, URL)
- `json` - Format, validate, or minify JSON
- `git-stats` - Git repository statistics

### Terminal Commands
- `help` - Show available commands
- `clear` - Clear screen and show banner
- `exit` - Exit ShellBox

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
