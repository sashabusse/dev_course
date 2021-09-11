#include <stdio.h>
#include <string.h>
int main()
{
    const char* str ="asdf";
    char* str2 = (char *) str;
    str2[2] = 'a';
    return 0;
}