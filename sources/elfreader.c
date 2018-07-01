#include "elfreader.h"
#include "fileio.h"

#define ELFD 0

int judgeType(FILE* fp)
{
    fseek(fp, 0, SEEK_SET);
    unsigned char buff[6];
    buff[5] = 0;
    int r = readBytes(fp, 5, buff);
    fseek(fp, 0, SEEK_SET);
#if ELFD
/*
    for(int i = 0; i < 5; i++)
        printf("%2x ", buff[i]);
    printf("\n");
*/
#endif

    if(r)
        return 3;
    if(buff[0] == '\x7f' && buff[1] == 'E' && buff[2] == 'L' && buff[3] == 'F')
    {
        if(buff[4] == '\x01')
            return 1;
        else if(buff[4] == '\x02')
            return 2;
        else
            return 3;
    }
    else
        return 3;    
}