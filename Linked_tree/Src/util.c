#include <stdlib.h>
#include <stdio.h>

void isOutOfBounds(int length, int index)
{
    if (index > length)
    {
        printf("out of bounds for index %d and length %d", index, length);
    }
}

void isMallocSuccesful(void *ptr)
{
    if (ptr == NULL)
    {
        printf("Memory allocation has failed (ptr is NULL)");
    }
}

void isArrayNull(int *array)
{
    if (array==NULL)
    {
        printf("The array is empty");
    }
}