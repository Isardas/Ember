#include "chunk.h"
#include "common.h"
#include "stdlib.h"
#include "debug.h"

int main(){
	Chunk * arr = malloc(sizeof(Chunk));
	initChunk(arr);
	int idx = addConstant(arr, 1.2);
	writeChunk(arr, OP_CONSTANT, 123);
	writeChunk(arr, idx, 123);
	writeChunk(arr, OP_RETURN, 123);
	disassembleChunk(arr, "Debug TEST");
	freeChunk(arr);
	free(arr);
	return 0;
}
