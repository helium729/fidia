#ifndef FILEIO
#define FILEIO

#include <stdio.h>
#include <stdlib.h>

//read one byte and stop reading
unsigned char readSingleByte(char* path, unsigned long location);

//read one byte in a opened file
unsigned char readByte(FILE *filePointer, unsigned long location);

unsigned char* readWord(FILE *filePointer, unsigned long location);

#endif