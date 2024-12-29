#include "genericType.h"

typedef struct Node
{
    var *value;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int length;
} LinkedList;

LinkedList *LinkedList_CreateEmptyList();
LinkedList *LinkedList_Create(var *array, int size);
void LinkedList_AddArray(LinkedList *list, var *array, int size);
void LinkedList_Add(LinkedList *list, var *value);
void LinkedList_AddAt(LinkedList *list, var *value, int index);
var *LinkedList_GetAt(LinkedList *list, int index);
void LinkedList_DeleteAt(LinkedList *list, int index);
void LinkedList_Print(LinkedList *list);
void LinkedList_PrintEvery1000th(LinkedList *list);
