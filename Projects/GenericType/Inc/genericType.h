typedef struct
{
    void *pointer;
} var;

var *set(void *variable);

void *get(var *variable);
