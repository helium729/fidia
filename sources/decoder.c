#include "decoder.h"

void linericScan(unsigned char* buffer, int number)
{
    unsigned char *p;
    p = buffer;
    int state = 0;
    while((p - buffer) < number)
    {
        if(*p == 0x48 && state == 0)
        {
            state = 1;
            p += 1;
        }
        else if(*p == 0x83 && state == 1)
        {
            printf("sub/add\n");
            state = 0;
            p += 3;
        }
        else if(*p == 0xc3 && !state)
        {
            printf("retq\n");
            state = 0;
            p += 1;
        }
        else if(*p == 0x74 && !state)
        {
            printf("je\n");
            state = 0;
            p += 2;
        }
        else if(*p == 0xff && !state)
        {
            state = 2;
            p += 1;
        }
        else if(state == 2)
        {
            if(*p == 0x35)
            {
                printf("pushq\n");
                p += 5;
                state = 0;
            }
            else if(*p == 25)
            {
                printf("jumpq\n");
                p += 5;
                state = 0;
            }
            else
            {
                printf("callq\n");
                p += 2;
                state = 0;
            }
        }
        else
        {
            state = 0;
            p += 1;
        }
    }
}