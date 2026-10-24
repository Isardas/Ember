#ifndef VALUE_H
#define VALUE_H

#include "common.h"
typedef double Value;

typedef struct {
	int capacity;
	int count;
	Value *value;
} ValueArray;

void writeValueArray(ValueArray * array, Value value);
void freeValueArray(ValueArray * array);
void initValueArray(ValueArray * array);

#endif
