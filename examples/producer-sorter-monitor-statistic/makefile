CC			= gcc
ROOT_DIR	= .
LIB_HEADERS	= -I$(ROOT_DIR)/lib/ -I$(ROOT_DIR)/lib/memory_handling/
LIB_SOURCES = $(ROOT_DIR)/lib/memory_handling/memory_handling.c
INCLUDE_LIB = $(LIB_HEADERS) $(LIB_SOURCES)

.PHONY: all clean producer sorter monitor

all: clean init_memory producer sorter monitor statistic

clean:
	rm -rf $(ROOT_DIR)/bin

create_bin_dir:
	mkdir -p $(ROOT_DIR)/bin

init_memory: create_bin_dir
	$(CC) $(INCLUDE_LIB) $(ROOT_DIR)/init_memory/init_memory.c -o $(ROOT_DIR)/bin/init_memory

producer: create_bin_dir
	$(CC) $(INCLUDE_LIB) $(ROOT_DIR)/producer/producer.c -o $(ROOT_DIR)/bin/producer

sorter: create_bin_dir
	$(CC) $(INCLUDE_LIB) $(ROOT_DIR)/sorter/sorter.c -o $(ROOT_DIR)/bin/sorter

monitor: create_bin_dir
	$(CC) $(INCLUDE_LIB) $(ROOT_DIR)/monitor/monitor.c -o $(ROOT_DIR)/bin/monitor

statistic: create_bin_dir
	$(CC) $(INCLUDE_LIB) $(ROOT_DIR)/statistic/statistic.c -o $(ROOT_DIR)/bin/statistic