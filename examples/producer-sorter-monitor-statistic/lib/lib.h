#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>

#include "memory_handling.h"

#define NO_NUM_IN_PROD_BUFFER -1
#define NO_NUM_IN_SORT_BUFFER -1

#define MAX_RAND_NUM 50
#define SORT_SIZE 10

struct DataBuffer
{
	int unsorted[SORT_SIZE];
	int sorted[SORT_SIZE];
};

struct DataHeader
{
	/* Used to track the number of the array which is already produced so far */
	int current_produce_number;

	/* Used to track the number of the array which is already sorted so far */
	int current_sort_number;
};

#endif