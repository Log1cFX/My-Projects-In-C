#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "util.h"

int main()
{
    int a[10];
    int b[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
        b[i] = i+10;
    }
    Linked_list *linked_list = linked_list_create(a, 10);
    //linked_list_add_array(linked_list, b, 10);
    linked_list_add_at(linked_list, 1, 20);

    int x = linked_list_get_at(linked_list, 2);
    printf("%d",x);
}
