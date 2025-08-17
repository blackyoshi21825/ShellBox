# Shell Box Commands

## Build Commands

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