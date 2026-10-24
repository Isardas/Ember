#include "debug.h"
#include "chunk.h"
#include "common.h"
#include "stdio.h"
#include "stdlib.h"

void disassembleChunk(Chunk *chunk, const char *msg){
	printf("== %s ==\n", msg);
	for(int offset = 0; offset < chunk->count;){
		offset = disassembleInstruction(chunk, offset);
	}
}

int disassembleInstruction(Chunk *chunk, int offset){
	printf("%04d ", offset);
	if(offset > 0 && chunk->lines[offset] == chunk->lines[offset-1]){
		printf("   | ");
	}
	else{
		printf("%4d ", chunk->lines[offset]);
	}
	uint8_t instruction = chunk->code[offset];
	switch(instruction){
		case OP_RETURN:
			return simpleInstruction("OP_RETURN", offset);
		case OP_CONSTANT:
			return constantInstruction("OP_CONSTANT", chunk, offset);
		default:
			printf("Unknown opcode %d\n", instruction);
			return offset + 1;
	}
}

int constantInstruction(const char *instruction, Chunk * chunk, int offset){
	int constantIndex = chunk->code[offset + 1];
	printf("%-16s %4d: '", instruction, constantIndex);
	printValue(chunk->constants.value[constantIndex]);
	printf("'\n");
	return offset + 2;
}

void printValue(Value value){
	printf("%g", value);
}

int simpleInstruction(const char *instruction, int offset){
	printf("%s\n", instruction);
	return offset + 1;
}
