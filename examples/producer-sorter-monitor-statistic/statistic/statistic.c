#include "statistic.h"

int main(int argc, char *argv[]) {

	void *memory = allocate_fabric_attached_memory();
	struct DataHeader *header = get_header_address(memory);
	struct DataBuffer *buffer = get_buffer_address(memory);

	struct NumberRanking ranking;
	struct NumberPrototype temp_proto_1, temp_proto_2;

	int pos, i, j, temp,
	    count_matrix[MAX_RAND_NUM];

	while (1) {
		pos = header->current_produce_number;
		if (pos != NO_NUM_IN_PROD_BUFFER) {
			printf("Calculating most produced numbers until position #%i\n", pos);

			/* Initialize the counts of all numbers */
			for (i = 0; i < MAX_RAND_NUM; i++)
				count_matrix[i] = 0;

			/* Initialize ranking */
			ranking.place_one.number = 0;
			ranking.place_one.count = 0;

			ranking.place_two.number = 0;
			ranking.place_two.count = 0;

			ranking.place_three.number = 0;
			ranking.place_three.count = 0;

			for (i = 0; i < pos; i++) {
				for (j = 0; j < SORT_SIZE; j++) {
					temp = (buffer + sizeof(struct DataBuffer) * i)->unsorted[j];

					/* Increase the count of the number gotten from the buffer. */
					count_matrix[temp - 1]++;
				}
			}

			/* Create the ranking for the three most produced numbers. */
			for (i = 0; i < MAX_RAND_NUM; i++) {
				if (count_matrix[i] > ranking.place_one.count) {
					temp_proto_1.number = ranking.place_one.number;
					temp_proto_1.count = ranking.place_one.count;

					temp_proto_2.number = ranking.place_two.number;
					temp_proto_2.count = ranking.place_two.count;

					ranking.place_one.number = i + 1;
					ranking.place_one.count = count_matrix[i];

					ranking.place_two.number = temp_proto_1.number;
					ranking.place_two.count = temp_proto_1.count;

					ranking.place_three.number = temp_proto_2.number;
					ranking.place_three.count = temp_proto_2.count;

				} else if (count_matrix[i] > ranking.place_two.count) {
					temp_proto_1.number = ranking.place_two.number;
					temp_proto_1.count = ranking.place_two.count;

					ranking.place_two.number = i + 1;
					ranking.place_two.count = count_matrix[i];

					ranking.place_three.number = temp_proto_1.number;
					ranking.place_three.count = temp_proto_1.count;

				} else if (count_matrix[i] > ranking.place_three.count) {
					ranking.place_three.number = i + 1;
					ranking.place_three.count = count_matrix[i];
				}
			}

			/* Print solution */
			printf("Place 1 - Number: %i | Count: %i\n", ranking.place_one.number,
			       ranking.place_one.count);
			printf("Place 2 - Number: %i | Count: %i\n", ranking.place_two.number,
			       ranking.place_two.count);
			printf("Place 3 - Number: %i | Count: %i\n", ranking.place_three.number,
			       ranking.place_three.count);

		} else {
			printf("Nothing produced yet.\n");
		}

		printf("Going to sleep and continue later...\n\n");
		sleep(SLEEPING_TIME);

		printf("Continue...\n");
	}
}