#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char r[1000];
    sprintf(r, "objdump -d %s", argv[1]);
    system(r);
    return 0;
}
