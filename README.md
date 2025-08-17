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
- 🔧 **System Tools** - CPU info, memory stats, network monitoring
- 📁 **File Operations** - Search, copy, hash, and manage files
- 🌐 **Network Utilities** - Port scanning and connectivity checks
- 📊 **Development Tools** - Git stats, JSON formatting, encoding utilities

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
