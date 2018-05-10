#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WINDOWS 1
#define LINUX 0

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

    //ToDo
    
    return 0;
}