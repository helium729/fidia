#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//read one byte and stop reading
unsigned char readSingleByte(char* path, unsigned long location);

//read one byte in a opened file
unsigned char readByte(FILE *filePointer, unsigned long location);

//read one word in a opened file
unsigned int readWord(FILE *filePointer, unsigned long location);

int readBytes(FILE *filePointer, int number, unsigned char* buffer);

void reverseStr(char* str);

#endif