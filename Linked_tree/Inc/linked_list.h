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
} Linked_list;

Linked_list *linked_list_create(int *, int size);
void linked_list_add_array(Linked_list *, int *array, int size);
void linked_list_add(Linked_list *, int value);
void linked_list_add_at(Linked_list *, int index, int value);
int linked_list_get_at(Linked_list *list, int index);
void linked_list_print(Linked_list *);