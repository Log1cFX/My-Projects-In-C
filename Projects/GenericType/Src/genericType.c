#include <stdlib.h>

#include "genericType.h"

var *set(void *variable)
{
    var *a = malloc(sizeof(var));
    a->pointer = variable;
    return a;
}

void *get(var *variable)
{
    return variable->pointer;
}