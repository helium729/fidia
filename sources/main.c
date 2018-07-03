#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

#include "fileio.h"
#include "elfreader.h"

//Main entrance of the program
int main(int argc, char * argv[])
{

#if DEBUG

#else
    if(argc != 2)
    {
        printf("Usage:\nfidia [inputPath]\n");
        //Program returns with args error
        return 0;
    }
    
    char *inputPath = argv[1];

    FILE* inputFilePointer = fopen(inputPath, "rb");
    if(inputFilePointer == NULL)
    {
	    printf("An IOException has occured when opening a file\nProgram returned -2\n");
	    return -2;
    }
    
    int type = judgeType(inputFilePointer);
    if(type == 3)
    {
        printf("Unknown file type, program returned -3\n");
        return -3;
    }

    int endianess = judgeEnding(inputFilePointer);
    if(endianess == 3)
    {
        printf("Unkown endianess, program returned -4\n");
        return -4;
    }

    //Only when little endianess
    struct ELF64Header header = readHeader(inputFilePointer);
    printf("Size of header: %ld bytes\n", sizeof(header));

    fclose(inputFilePointer);
#endif

    

    return 0;
}