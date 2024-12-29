#include <stdlib.h>

#define var void

#define genericType(T)                        \
    T *Type_get_##T(var *variable)            \
    {                                         \
        return variable;                      \
    }                                         \
    /*preferably only used with basic         \
    datatypes like int, char, long, etc... */ \
    T *Type_set_##T(T variable)               \
    {                                         \
        var *a = malloc(sizeof(var));         \
        T *temp = malloc(sizeof(T));          \
        *temp = variable;                     \
        a = temp;                             \
        return a;                             \
    }
