#include "sorter.h"

int main(int argc, char *argv[]) {

	void *memory = allocate_fabric_attached_memory();
	struct DataHeader *header = get_header_address(memory);
	struct DataBuffer *buffer = get_buffer_address(memory);

	int i;

	printf("Checking where to start to sort numbers...\n");

	/* Check where to start to sort numbers */
	i = header->current_sort_number == NO_NUM_IN_SORT_BUFFER ? 0 : (header->current_sort_number + 1);

	while (1) {
		if (header->current_produce_number >= i) {
			printf("Start sorting numbers at position #%i\n", i);

			sort(buffer, i);
			print_sorted_items(buffer, i);

			/* Tell the world you are done with producing numbers for this segment */
			header->current_sort_number = i;
			i++;

			printf("Finished to sort the numbers at position #%i\n", (i - 1));
		} else {
			printf("No further items have been found which need to be sorted.\n");
			i = header->current_sort_number == NO_NUM_IN_SORT_BUFFER ? 0 : (header->current_sort_number + 1);
		}

		printf("Going to sleep and continue later...\n\n");
		sleep(SLEEPING_TIME);

		printf("Continue...\n");
	}

	return 0;
}

void sort(struct DataBuffer *buffer, int pos) {
	bubbleSort((buffer + sizeof(struct DataBuffer) * pos)->unsorted, (buffer + sizeof(struct DataBuffer) * pos)->sorted, SORT_SIZE);
}

void print_sorted_items(struct DataBuffer *buffer, int pos) {

	int i;

	buffer = buffer + sizeof(struct DataBuffer) * pos;
	printf("Sorted the numbers: [ ");
	for (i = 0; i < SORT_SIZE; i++)
		printf("%i ", buffer->sorted[i]);

	printf("]\n");
}

void bubbleSort(int *const src, int *dest, unsigned int const length) {

	int i, temp;
	char check = 1;

	for (i = 0; i < length; i++)
		dest[i] = src[i];

	while (check) {
		check = 0;

		for (i = 0; i < (length - 1); i++) {
			if (dest[i] > dest[i + 1]) {
				temp = dest[i + 1];
				dest[i + 1] = dest[i];
				dest[i] = temp;

				check = 1;
			}
		}
	}
}