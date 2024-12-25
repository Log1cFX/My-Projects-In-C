#include <stdio.h>

#include "genericType.h"

int main()
{
    int temp = 10;
    void *b = &temp;
    var *a = set(b);
    printf("%d", get(a));
}