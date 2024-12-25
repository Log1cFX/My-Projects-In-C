#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include<windows.h>

#include "linked_list.h"
#include "util.h"

int main()
{
    LinkedList *list = LinkedList_CreateEmptyList();
    clock_t t; 
    t = clock();
    for (int i = 1; i < 10000000; i++)
    {
        LinkedList_Add(list, i);
    }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken: %f\n",time_taken);
}
