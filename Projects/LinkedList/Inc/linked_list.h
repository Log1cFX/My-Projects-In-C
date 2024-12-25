typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int length;
} LinkedList;

LinkedList *LinkedList_CreateEmptyList();
LinkedList *LinkedList_Create(int *array, int size);
void LinkedList_AddArray(LinkedList *list, int *array, int size);
void LinkedList_Add(LinkedList *list, int value);
void LinkedList_AddAt(LinkedList *list, int index, int value);
int LinkedList_GetAt(LinkedList *list, int index);
void LinkedList_DeleteAt(LinkedList *list, int index);
void LinkedList_Print(LinkedList *list);
void LinkedList_PrintEvery1000th(LinkedList *list);
