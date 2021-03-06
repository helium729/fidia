#include "elfreader.h"
#include "fileio.h"

#define ELFD 0

//tested
int judgeType(FILE* fp)
{
    fseek(fp, 0, SEEK_SET);

    unsigned char buff[8];
    buff[7] = 0;
    int r = readBytes(fp, 7, buff);

    fseek(fp, 0, SEEK_SET);

    if(r)
        return 3;
    if(buff[0] == '\x7f' && buff[1] == 'E' 
    && buff[2] == 'L' && buff[3] == 'F' && buff[6] == '\x01')
    {
        if(buff[4] == '\x01')
        {
            printf("\nThis is an ELF32 file\n");
            return 1;
        }
        else if(buff[4] == '\x02')
        {
            printf("This is an ELF64 file\n");
            return 2;
        }
        else
            return 3;
    }
    else
        return 3;    
}

//tested
int judgeEnding(FILE* fp)
{
    fseek(fp, 0x05, SEEK_SET);

    unsigned char buffer[2];
    buffer[1] == 0;
    int r = readBytes(fp, 1, buffer);
    if(buffer[0] == '\x01')
    {
        printf("Little endianess\n");
        return 1;
    }
    else if(buffer[0] == '\x02')
    {
        printf("Big endianess\n");
        return 2;
    }
    else
        return 3;

    fseek(fp, 0, SEEK_SET);
}

//tested
Elf64_Ehdr readHeader(FILE* fp)
{
    fseek(fp, 0, SEEK_SET);

    struct ELF64Header header;
    fread(&header, sizeof(Elf64_Ehdr), 1, fp);

    fseek(fp, 0, SEEK_SET);

    return header;
}

//tested
Elf64_Shdr* readSectionHeader(FILE* fp, Elf64_Offset offset, Elf64_Half num)
{
    fseek(fp, offset, SEEK_SET);

    struct ELF64SectionHeader* header;
    header = (Elf64_Shdr*)malloc(sizeof(Elf64_Shdr)*num);
    fread(header, sizeof(Elf64_Shdr), num, fp);

    return header;
}