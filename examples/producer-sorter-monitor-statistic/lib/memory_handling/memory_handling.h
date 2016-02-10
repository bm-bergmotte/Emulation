#ifndef MEMORY_HANDLING_H
#define MEMORY_HANDLING_H

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "lib.h"

#define ONE_GiB 1073741824

void *allocate_fabric_attached_memory();
struct DataHeader *get_header_address(void *memory);
struct DataBuffer *get_buffer_address(void *memory);

#endif