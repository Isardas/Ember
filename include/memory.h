#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"

#define GROW_CAPACITY(capacity) \
	((capacity) < 8 ? 8 : 2*(capacity))

#define GROW_ARRAY(type, pointer, oldCapacity, newCapacity) \
	(type*)reallocate(pointer, sizeof(type) *(oldCapacity), sizeof(type)*(newCapacity))

#define FREE_ARRAY(type, array, capacity) \
	reallocate(array, sizeof(type) * capacity, 0)


void * reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif
