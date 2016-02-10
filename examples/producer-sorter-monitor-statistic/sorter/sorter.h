#ifndef SORTER_H
#define SORTER_H

#include "lib.h"

#define SLEEPING_TIME 2

void bubbleSort(int *const src, int *dest, unsigned int length);
void sort(struct DataBuffer *buffer, int pos);
void print_sorted_items(struct DataBuffer *buffer, int pos);

#endif