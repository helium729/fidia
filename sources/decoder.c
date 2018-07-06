#include "decoder.h"

void linericScan(unsigned char* buffer, int number, Elf64_Offset offset)
{
    unsigned char *p;
    p = buffer;
    int state = 0;
    while((p - buffer) < number)
    {
        Elf64_Offset location = offset + (p - buffer);
        if(*p == 0x48 && !state)
        {
            state = 1;
            p += 1;
        }
        else if(*p == 0x83 && state == 1)
        {
            printf("0x%lx add/and\n", location - 1);
            state = 0;
            p += 3;
        }
        else if(*p == 0x85 && state == 1)
        {
            printf("0x%lx test\n", location - 1);
            state = 0;
            p += 2;
        }
        else if(*p == 0x89 && state == 1)
        {
            printf("0x%lx mov\n", location - 1);
            state = 0;
            p += 2;
        }
        else if(*p == 0x8d && state == 1)
        {
            printf("0x%lx lea\n", location - 1);
            state = 0;
            p += 6;
        }
        else if(*p == 0xc3 && !state)
        {
            printf("0x%lx retq\n", location);
            state = 0;
            p += 1;
        }
        else if(*p == 0x74 && !state)
        {
            printf("0x%lx je\n", location);
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
                printf("0x%lx pushq\n", location - 1);
                p += 5;
                state = 0;
            }
            else if(*p == 25)
            {
                printf("0x%lx jmpq\n", location - 1);
                p += 5;
                state = 0;
            }
            else
            {
                printf("0x%lx callq\n", location - 1);
                p += 2;
                state = 0;
            }
        }
        else if(*p == 0x0f && !state)
        {
            printf("0x%lx nopl\n", location);
            p += 4;
            state = 0;
        }
        else if(*p == 0x68 && !state)
        {
            printf("0x%lx pushq\n", location);
            p += 5;
            state = 0;
        }
        else if(*p == 0xe9 && !state)
        {
            printf("0x%lx jmpq\n", location);
            p += 5;
            state = 0;
        }
        else if(*p == 0x66 && !state)
        {
            state = 3;
            p += 1;
            state = 0;
        }
        else if(state == 3)
        {
            if(*p == 0x2e)
            {
                printf("0x%lx nopw\n", location - 1);
                state = 0;
                p += 6;
            }
            else
            {
                printf("0x%lx xchg\n", location - 1);
                state = 0;
                p += 1;
            }
        }
        else if(*p == 0x55 && !state)
        {
            printf("0x%lx push\n", location);
            p += 1;
            state = 0;
        }
        else if((*p == 0x5e || *p == 0x5b || *p == 0x5d || *p == 0x4e) && !state)
        {
            printf("0x%lx pop\n", location);
            p += 1;
            state = 0;
        }
        else if(*p == 0x31 && !state)
        {
            printf("0x%lx xor\n", location);
            p += 2;
            state = 0;
        }
        else if(*p == 0xf4 && !state)
        {
            printf("0x%lx hlt\n", location);
            p += 1;
            state = 0;
        }
        else if(*p == 0x75 && !state)
        {
            printf("0x%lx jne\n", location);
            p += 2;
            state = 0;
        }
        else
        {
            state = 0;
            p += 1;
        }
    }
}