#include <stdio.h>
#include <stdint.h>

struct bitField {
    uint8_t a : 4;
    uint8_t var;
};

int main()
{
    struct bitField f;
    f.var = 100;
    f.a = 8;
    printf("%d\n",sizeof(struct bitField));
    printf("%d",f.var);
}
