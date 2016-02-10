#ifndef PRODUCER_H
#define PRODUCER_H

#include "lib.h"

#define SLEEPING_TIME 3

void produce(struct DataBuffer *buffer, int pos);
void print_produced_items(struct DataBuffer *buffer, int pos);

#endif