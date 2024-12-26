#include <stdlib.h>

typedef struct
{
    void *pointer;
} var;

var *set_pointer(void *variable);

void *get_void(var *variable);

#define genericType(T)                        \
    T *get_##T(var *variable)                 \
    {                                         \
        return variable->pointer;             \
    }                                         \
    /*preferably only used with basic         \
    datatypes like int, char, long, etc... */ \
    var *set_##T(T variable)                  \
    {                                         \
        var *a = malloc(sizeof(var));         \
        T *temp = malloc(sizeof(T));          \
        *temp = variable;                     \
        a->pointer = temp;                    \
        return a;                             \
    }
