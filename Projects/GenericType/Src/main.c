#include <stdio.h>

#include "genericType.h"

int main()
{
    genericType(int);
    var *a = set_int(10);
    printf("%d\n", *get_int(a));

    var *b = set_pointer("Hello World");
    printf("%s\n",(char*)get_void(b));
}