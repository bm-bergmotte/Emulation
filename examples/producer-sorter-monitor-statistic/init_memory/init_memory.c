#include "lib.h"

int main(int argc, char *argv[]) {
	
	void *memory = allocate_fabric_attached_memory();
	struct DataHeader *header = get_header_address(memory);

	/* Initialize header with default values */
	header->current_produce_number = NO_NUM_IN_PROD_BUFFER;
	header->current_sort_number = NO_NUM_IN_SORT_BUFFER;

	/* Release mapping */
	munmap(header, sizeof(struct DataHeader));

	printf("The fabric attached memory has been initialized.\n");

	return 0;
}