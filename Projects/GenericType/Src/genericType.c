#include <stdlib.h>

#include "genericType.h"

/// @brief creates a var struct with a void pointer, pointing to the variable, allocated in the heap
/// @param the adress of the variable
/// @return initialized var struct, with a void pointer to the variable
var *set_pointer(void *variable)
{
    var *a = malloc(sizeof(var));
    a->pointer = variable;
    return a;
}

/// @brief fancy way to do var->pointer
/// @param the var struct
/// @return a void pointer, pointing to the variable
void *get_void(var *variable)
{
    return variable->pointer;
}