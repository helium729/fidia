#ifndef FILEIO
#define FILEIO

#include <stdio.h>
#include <stdlib.h>

unsigned char readSingleByte(char* path, unsigned long location);

unsigned char readByte(FILE *filePointer, unsigned long location);

#endif