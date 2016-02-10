#ifndef MONITOR_H
#define MONITOR_H

#include "lib.h"

#define SLEEPING_TIME 4

void check_if_something_to_show(struct DataHeader *header);
void print_numbers(struct DataHeader *header, struct DataBuffer *buffer, int pos);

#endif