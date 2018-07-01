#include <stdio.h>
#include <stdlib.h>

#define WINDOWS 1
#define LINUX 0
#define DEBUG 0

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

    FILE* fp;
    fp = fopen("./test0", "rb");
    int r = judgeType(fp);
    printf("%d\n", r);
    fclose(fp);

#else
    if(argc != 2)
    {
        printf("Usage:\nfidia [inputPath]\n");
        //Program returns with args error
        return -1;
    }
    
    char *inputPath = argv[1];

    FILE* inputFilePointer = fopen(inputPath, "rb");
    
    if(inputFilePointer == NULL)
    {
	    printf("An IOException has occured when opening a file\nProgram returned -2\n");
        //Program returns with an IO Exception
	    return -2;
    }
    
    int type = judgeType(inputFilePointer);
    
    if(type == 1)
        printf("This is an ELF32 file\n\n");
    else if(type == 2)
        printf("This is an ELF64 file\n\n");
    else if(type == 3)
    {
        printf("Unknown file type, program returned -3\n");
        return -3
    }

    fclose(inputFilePointer);
#endif

    return 0;
}