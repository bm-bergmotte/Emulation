#include "monitor.h"

int main(int argc, char *argv[]) {

	void *memory = allocate_fabric_attached_memory();
	struct DataHeader *header = get_header_address(memory);
	struct DataBuffer *buffer = get_buffer_address(memory);

	int i;

	check_if_something_to_show(header);
	i = header->current_sort_number;

	while (1) {


		if (header->current_sort_number >= i) {
			print_numbers(header, buffer, i);
			i++;
		} else {
			printf("Nothing new to show...\n");
			check_if_something_to_show(header);
			i = header->current_sort_number + 1;
		}
		printf("Going to sleep and continue later...\n\n");
		sleep(SLEEPING_TIME);

		printf("Continue...\n");
	}

	return 0;
}

void check_if_something_to_show(struct DataHeader *header) {
	while (header->current_produce_number == NO_NUM_IN_PROD_BUFFER) {
		printf("No numbers have been produced so far.\n");
		printf("Going to sleep and continue later...\n\n");
		sleep(SLEEPING_TIME);

		printf("Continue...\n");
	}

	while (header->current_sort_number == NO_NUM_IN_SORT_BUFFER) {
		printf("Numbers have been produced but not sorted yet.\n");
		printf("Going to sleep and continue later...\n\n");
		sleep(SLEEPING_TIME);

		printf("Continue...\n");
	}
}

void print_numbers(struct DataHeader *header, struct DataBuffer *buffer, int pos) {

	int i;

	if (header->current_sort_number != NO_NUM_IN_SORT_BUFFER) {
		printf("Unsorted array #%i :\t[ ", pos);
		for (i = 0; i < SORT_SIZE; i++)
			printf("%i ", (buffer + sizeof(struct DataBuffer) * pos)->unsorted[i]);

		printf("]\n");

		printf("Sorted array #%i :\t[ ", pos);
		for (i = 0; i < SORT_SIZE; i++)
			printf("%i ", (buffer + sizeof(struct DataBuffer) * pos)->sorted[i]);

		printf("] \n");
	}
}