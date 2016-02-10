#include "producer.h"

int main(int argc, char *argv[]) {

	void *memory = allocate_fabric_attached_memory();
	struct DataHeader *header = get_header_address(memory);
	struct DataBuffer *buffer = get_buffer_address(memory);

	int i;
	time_t t;

	/* Set seed for rand() */
	srand((unsigned) time(&t));

	printf("Checking where to start to insert new numbers...\n");

	/* Check where to start to insert new numbers */
	i = header->current_produce_number == NO_NUM_IN_PROD_BUFFER ? 0 : (header->current_produce_number + 1);

	while (1) {
		/* For the case someone initializes the header while producing numbers */
		if ((i - 1) == header->current_produce_number || header->current_produce_number != NO_NUM_IN_PROD_BUFFER) {
			printf("Start inserting numbers at position #%i\n", i);

			produce(buffer, i);
			print_produced_items(buffer, i);

			/* Tell the world you are done with producing numbers for this segment */
			header->current_produce_number = i;
			i++;

			printf("Finished to insert numbers at position #%i into the fabric attached memory\n", i);

		} else {
			printf("Checking where to start to insert new numbers...\n");
			i = header->current_produce_number == NO_NUM_IN_PROD_BUFFER ? 0 : (header->current_produce_number + 1);
		}

		printf("Going to sleep and continue later...\n\n");

		sleep(SLEEPING_TIME);
		printf("Continue...\n");
	}

	return 0;
}

void produce(struct DataBuffer *buffer, int pos) {

	int i;

	buffer = buffer + sizeof(struct DataBuffer) * pos;
	for (i = 0; i < SORT_SIZE; i++)
		buffer->unsorted[i] = rand() % MAX_RAND_NUM + 1; // Do you realize that this is already persistent? Cool huh! ;-)
}

void print_produced_items(struct DataBuffer *buffer, int pos) {

	int i;

	buffer = buffer + sizeof(struct DataBuffer) * pos;
	printf("Produced the numbers: [ ");
	for (i = 0; i < SORT_SIZE; i++)
		printf("%i ", buffer->unsorted[i]);

	printf("]\n");
}