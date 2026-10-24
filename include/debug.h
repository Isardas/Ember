#ifndef DEBUG_H
#define DEBUG_H
#include "common.h"
#include "chunk.h"

void disassembleChunk(Chunk *chunk, const char *msg);
int disassembleInstruction(Chunk *chunk, int offset);
int simpleInstruction(const char *instruction, int offset);
int constantInstruction(const char *instruction, Chunk * chunk, int offset);
void printValue(Value value);

#endif
