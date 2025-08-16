CC=gcc
CFLAGS=-Wall -O2
SRC=src
BIN=bin

UTILS = cpuinfo meminfo file_search netstat
EXTRA = copytree deltree file_info find_duplicates hello

all: $(addprefix $(BIN)/shellbox-,$(UTILS)) $(addprefix $(BIN)/,$(EXTRA))

$(BIN)/shellbox-%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<

$(BIN)/%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BIN)/*

# Run compiled C programs
shellbox-hello:
	@./bin/hello

shellbox-cpuinfo:
	@./bin/shellbox-cpuinfo

shellbox-meminfo:
	@./bin/shellbox-meminfo

shellbox-file-search:
	@./bin/shellbox-file_search

shellbox-netstat:
	@./bin/shellbox-netstat

shellbox-copytree:
	@./bin/copytree

shellbox-deltree:
	@./bin/deltree

shellbox-file-info:
	@./bin/file_info

shellbox-find-duplicates:
	@./bin/find_duplicates

# Run shell scripts
shellbox-backup:
	bash scripts/backup.sh

shellbox-delete-empty-dirs:
	bash scripts/delete_empty_dirs.sh

shellbox-disk-usage:
	bash scripts/disk_usage.sh

shellbox-find-large-files:
	bash scripts/find_large_files.sh

shellbox-folder-size:
	bash scripts/folder_size.sh

shellbox-move-files:
	bash scripts/move_files.sh

shellbox-network-info:
	bash scripts/network_info.sh

shellbox-process-list:
	bash scripts/process_list.sh

shellbox-rename-batch:
	bash scripts/rename_batch.sh

shellbox-sync-dirs:
	bash scripts/sync_dirs.sh

shellbox-sys-info:
	bash scripts/sys_info.sh