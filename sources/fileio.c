#include "fileio.h"

#define IOD 0

unsigned char readSingleByte (char* path, unsigned long location)
{
	FILE *fp = NULL;
	unsigned char ch;
	fp = fopen(path, "rb");
	
	ch = readByte(fp, location);

	return ch;
}

unsigned char readByte(FILE *filePointer, unsigned long location)
{
	unsigned char ch[2];
	if (filePointer == NULL)      
	{
	    printf("An IOException has occured when opening a file\nError section: byte %ld\n", location);
	    return 0;
	}

	fseek(filePointer, location, SEEK_SET);
	fread(ch, sizeof(char), 1, filePointer);

	return ch[0];
}

unsigned int readWord(FILE *filePointer, unsigned long location)
{
	if (filePointer == NULL)      
	{
	    printf("An IOException has occured when opening a file\n");
	    return 0;
	}
	
	unsigned int result = 0;
	unsigned long byteLocation = location * 4;
	for(int i = 0; i < 4; i++)
	{
		unsigned int temp = (unsigned int)readByte(filePointer, byteLocation + i);
		result += temp << (24 - 8 * i);
	}
	return result;
}

int readBytes(FILE *filePointer, int number, unsigned char* buffer)
{
	if (filePointer == NULL)      
	{
	    printf("An IOException has occured when opening a file\n");
	    return 0;
	}

	int r = fread(buffer, sizeof(char), number, filePointer);

#if IOD
	//printf("%d\n", r);
#endif

	if(r != number)
		return r;
	else
		return 0;
}

void reverseStr(char* str)
{
	char* buffer;
	int offset = 0;
	buffer = (char*)malloc(sizeof(str)/sizeof(char));
	while(*(str + offset))
	{
		*(buffer + offset) = *(str + offset);
		offset += 1;
	}
	offset -= 1;
	int counter;
	for(counter = 0; offset >= 0; offset --)
	{
		*(str + counter) = *(buffer + offset);
		counter += 1;
	}
	*(str + counter) = '\x0';
}