#include "fileio.h"

unsigned char readSingleByte (char* path, unsigned long location)
{
	FILE *fp = NULL;
	unsigned char ch[2];
	fp = fopen(path, "rb");
	
	if (fp == NULL)      
	{
	    printf("An IOException has occured when opening a file\n");
	    return 0;
	}
	
	fseek(fp, location, 0);
	fread(ch, sizeof(ch), 1, fp); 
	
	fclose(fp);
	return ch[0];
}

unsigned char readByte(FILE *filePointer, unsigned long location)
{
	unsigned char ch[2];
	if (filePointer == NULL)      
	{
	    printf("An IOException has occured when opening a file\n");
	    return 0;
	}

	fseek(filePointer, location, 0);
	fread(ch, sizeof(ch), 1, filePointer); 
}