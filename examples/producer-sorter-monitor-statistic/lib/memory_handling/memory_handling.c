#include "memory_handling.h"

void *allocate_fabric_attached_memory() {
	int fd;
	void *buffer;

	if ((fd = open("/mnt/fabric_emulation", O_RDWR)) == -1) {
		perror("open failed");
		exit(1);
	}

	if ((buffer = mmap(NULL, ONE_GiB, PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED) {
		perror("mmap failed");
		exit(1);
	}

	return buffer;
}

struct DataHeader *get_header_address(void *memory) {
	return (struct DataHeader*) memory;
}

struct DataBuffer *get_buffer_address(void *memory) {
	return (struct DataBuffer*) (memory + sizeof(struct DataHeader));
}