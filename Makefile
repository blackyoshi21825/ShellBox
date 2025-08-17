CC=gcc
CFLAGS=-Wall -O2
SRC=src
BIN=bin

UTILS = cpuinfo meminfo file_search netstat grep hash uptime
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

sb-grep: $(BIN)/sb-grep
	@if [ -z "$(PATTERN)" ] || [ -z "$(FILE)" ]; then \
		echo "Usage: make sb-grep PATTERN='pattern' FILE='filename'"; \
	else \
		./bin/sb-grep "$(PATTERN)" "$(FILE)"; \
	fi

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

sb-hash: $(BIN)/sb-hash
	@if [ -z "$(FILE)" ]; then \
		echo "Usage: make sb-hash FILE='filename' [TYPE='md5|sha256']"; \
	else \
		./bin/sb-hash "$(FILE)" "$(TYPE)"; \
	fi

sb-uptime: $(BIN)/sb-uptime
	@./bin/sb-uptime

sb-encode:
	@if [ -z "$(ACTION)" ] || [ -z "$(TYPE)" ] || [ -z "$(TEXT)" ]; then \
		echo "Usage: make sb-encode ACTION='encode|decode' TYPE='base64|url' TEXT='text'"; \
	else \
		bash scripts/encode.sh "$(ACTION)" "$(TYPE)" "$(TEXT)"; \
	fi

sb-json:
	@if [ -z "$(ACTION)" ]; then \
		echo "Usage: make sb-json ACTION='format|validate|minify' [FILE='filename']"; \
	elif [ -n "$(FILE)" ]; then \
		bash scripts/json_format.sh "$(ACTION)" "$(FILE)"; \
	else \
		echo "Pipe JSON to this command or specify FILE parameter"; \
	fi

sb-git-stats:
	bash scripts/git_stats.sh

sb-port-check:
	@if [ -z "$(HOST)" ] || [ -z "$(PORT)" ]; then \
		echo "Usage: make sb-port-check HOST='hostname' PORT='port' [TIMEOUT='seconds']"; \
		echo "       make sb-port-check ACTION='scan' HOST='hostname' START='start_port' END='end_port'"; \
	elif [ "$(ACTION)" = "scan" ]; then \
		bash scripts/port_check.sh scan "$(HOST)" "$(START)" "$(END)"; \
	else \
		bash scripts/port_check.sh "$(HOST)" "$(PORT)" "$(TIMEOUT)"; \
	fi