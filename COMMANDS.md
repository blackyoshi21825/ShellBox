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
- `make shellbox-cpuinfo` - Display CPU information
- `make shellbox-meminfo` - Display memory information
- `make shellbox-netstat` - Display network statistics

### File Operations
- `make shellbox-file-search` - Search for files
- `make shellbox-file-info` - Display file information
- `make shellbox-find-duplicates` - Find duplicate files
- `make shellbox-copytree` - Copy directory trees
- `make shellbox-deltree` - Delete directory trees

### Utilities
- `make shellbox-hello` - Hello world program

## Shell Script Commands

### File Management
- `make shellbox-backup` - Backup files and directories
- `make shellbox-move-files` - Move files based on criteria
- `make shellbox-rename-batch` - Batch rename files
- `make shellbox-sync-dirs` - Synchronize directories

### System Analysis
- `make shellbox-disk-usage` - Display disk usage information
- `make shellbox-folder-size` - Calculate folder sizes
- `make shellbox-find-large-files` - Find large files on system
- `make shellbox-delete-empty-dirs` - Remove empty directories

### System Information
- `make shellbox-sys-info` - Display system information
- `make shellbox-network-info` - Display network information
- `make shellbox-process-list` - List running processes