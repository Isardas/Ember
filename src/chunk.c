#include "chunk.h"
#include "memory.h"
#include "stdio.h"
#include "value.h"

void initChunk(Chunk* chunk){
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->code = NULL;
}

void writeChunk(Chunk * chunk, uint8_t byte, int line){
	if(chunk->count >= chunk->capacity){
		int oldCapacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(oldCapacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
		chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
	}

	chunk->code[chunk->count] = byte;
	chunk->lines[chunk->count] = line;
	chunk->count++;
}

int addConstant(Chunk *chunk, Value value){
	writeValueArray(&chunk->constants, value);
	return chunk->constants.count - 1;
}

void freeChunk(Chunk * chunk){
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	FREE_ARRAY(int, chunk->lines, chunk->capacity);
	freeValueArray(&chunk->constants);
	initChunk(chunk); // To zero out all fields
}
