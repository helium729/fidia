#include <stdio.h>

#define WINDOWS 1
#define LINUX 0

#include "fileio.h"

//Main entrance of the program
int main(int argc, char * argv[])
{
    if(argc != 3)
    {
        printf("Usage:\nfidia [inputPath] [outputPath]\n");
        //Program returns with args error
        return -1;
    }
    
    char *inputPath = argv[1];
    char *outputPath = argv[2];

    FILE *inputFilePointer = NULL;
    fopen(inputPath, "rb");

    if(inputFilePointer == NULL)
    {
	    printf("An IOException has occured when opening a file\nProgram returned -2\n");
        //Program returns with an IO Exception
	    return -2;
    }

#if WINDOWS
    //ToDo
#endif //WINDOWS
    
    fclose(inputFilePointer);

    return 0;
}