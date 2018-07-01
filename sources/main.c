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


    //FILE* fp;
    //fp = fopen("./test0", "rb");

    //int r = judgeType(fp);
    //int r = judgeEnding(fp);  
    //printf("%d\n", r);
    char a[8] = "dasdfgh";
    reverseStr(a);
    printf("%s\n",a);

    //fclose(fp);
*/

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
        //Program returns with an IO Exception
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

    fclose(inputFilePointer);
#endif

    return 0;
}