#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void leak()
{
    char* a = (char*)malloc(4096);
    a[0] = 1;
}
void main()
{
    int a = 0;
    while (1)
    {
        leak();
        a++;
        if (a==1024)
        {
            fork();
            a=0;
        }
    }
}