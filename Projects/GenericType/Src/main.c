#include <stdio.h>

#include "genericType.h"

int main()
{
    int temp = 10;
    var *a = set(&temp);
    printf("%d", *(int*)get(a));
}