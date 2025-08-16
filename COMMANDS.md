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

### File Operations
- `make sb-file-search` - Search for files
- `make sb-file-info` - Display file information
- `make sb-find-duplicates` - Find duplicate files
- `make sb-copytree` - Copy directory trees
- `make sb-deltree` - Delete directory trees

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