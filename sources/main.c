#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

#include "fileio.h"
#include "elfreader.h"
#include "decoder.h"

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
    printf("Program offset: 0x%lx\tSection Offset: 0x%lx\n", header.e_poff, header.e_soff);
    printf("Section header size:%ld \tHeader number: %d\n", sizeof(Elf64_Shdr), header.e_shnum);


    unsigned char buffer[10000];
    Elf64_Shdr textHeader;
    Elf64_Shdr* sections = readSectionHeader(inputFilePointer, header.e_soff, header.e_shnum);
    for(int i = 0; i < header.e_shnum; i ++)
    {
        //printf("%lx\n", (sections + i)->sh_flags);
        if((sections + i)->sh_flags == 0x6)
            textHeader = *(sections + i);
        else
            continue;
        printf("\nSection offset: 0x%lx\n", textHeader.sh_offset);
        printf("Section size : %ld\n", textHeader.sh_size);
        fseek(inputFilePointer, textHeader.sh_offset, SEEK_SET);

        
        printf("%ld", sizeof(buffer)/sizeof(unsigned char));

        fread(buffer, sizeof(char), textHeader.sh_size, inputFilePointer);
        for(int j = 0; j < textHeader.sh_size; j++)
            //printf("%2x ", *(buffer + j));
        //printf("\n");
        linericScan(buffer, textHeader.sh_size);

    }
    free(sections);

    fclose(inputFilePointer);
#endif

    

    return 0;
}