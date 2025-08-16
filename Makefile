CC=gcc
CFLAGS=-Wall -O2
SRC=src
BIN=bin

UTILS = cpuinfo meminfo file_search netstat
EXTRA = copytree deltree file_info find_duplicates hello

all: $(addprefix $(BIN)/sb-,$(UTILS)) $(addprefix $(BIN)/,$(EXTRA))

$(BIN)/sb-%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<

$(BIN)/%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BIN)/*

# Run compiled C programs
sb-hello: $(BIN)/hello
	@./bin/hello

sb-cpuinfo: $(BIN)/sb-cpuinfo
	@./bin/sb-cpuinfo

sb-meminfo: $(BIN)/sb-meminfo
	@./bin/sb-meminfo

sb-file-search: $(BIN)/sb-file_search
	@./bin/sb-file_search

sb-netstat: $(BIN)/sb-netstat
	@./bin/sb-netstat

sb-copytree: $(BIN)/copytree
	@./bin/copytree

sb-deltree: $(BIN)/deltree
	@./bin/deltree

sb-file-info: $(BIN)/file_info
	@./bin/file_info

sb-find-duplicates: $(BIN)/find_duplicates
	@./bin/find_duplicates

# Run shell scripts
sb-backup:
	bash scripts/backup.sh

sb-delete-empty-dirs:
	bash scripts/delete_empty_dirs.sh

sb-disk-usage:
	bash scripts/disk_usage.sh

sb-find-large-files:
	bash scripts/find_large_files.sh

sb-folder-size:
	bash scripts/folder_size.sh

sb-move-files:
	bash scripts/move_files.sh

sb-network-info:
	bash scripts/network_info.sh

sb-process-list:
	bash scripts/process_list.sh

sb-rename-batch:
	bash scripts/rename_batch.sh

sb-sync-dirs:
	bash scripts/sync_dirs.sh

sb-sys-info:
	bash scripts/sys_info.sh