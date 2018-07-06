#ifndef DECODER_H
#define DECODER_H

#include <stdio.h>
#include "elfreader.h"

//Fool's way
void linericScan(unsigned char* buffer, int number, Elf64_Offset offset);

#endif