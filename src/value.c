#include "memory.h"
#include "common.h"
#include "value.h"

void initValueArray(ValueArray *array){
	array->capacity = 0;
	array->count = 0;
	array->value = NULL;
}

void freeValueArray(ValueArray *array){
	FREE_ARRAY(Value, array->value, array->capacity);
	initValueArray(array);
}

void writeValueArray(ValueArray *array, Value value){
	if(array->count >= array->capacity){
		int oldCapacity = array->capacity;
		array->capacity = GROW_CAPACITY(oldCapacity);
		array->value = GROW_ARRAY(Value, array->value, oldCapacity, array->capacity);
	}

	array->value[array->count++] = value; 
}
