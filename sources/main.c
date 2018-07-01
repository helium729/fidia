#include <stdio.h>
#include <stdlib.h>

#define WINDOWS 1
#define LINUX 0
#define DEBUG 1

#include "fileio.h"
#include "elfreader.h"

//Main entrance of the program
int main(int argc, char * argv[])
{

#if DEBUG
/*
    int size = 0;
    size = sizeof(Elf32_Ehdr) / sizeof(char);
    printf("%d\n", size);
*/
#else
    if(argc != 3)
    {
        printf("Usage:\nfidia [inputPath] [outputPath]\n");
        //Program returns with args error
        return -1;
    }
    
    char *inputPath = argv[1];
    char *outputPath = argv[2];
    FILE* inputFilePointer = fopen(inputPath, "rb");
    
    if(inputFilePointer == NULL)
    {
	    printf("An IOException has occured when opening a file\nProgram returned -2\n");
        //Program returns with an IO Exception
	    return -2;
    }
    
    fclose(inputFilePointer);
#endif

    return 0;
}