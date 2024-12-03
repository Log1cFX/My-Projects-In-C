#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "util.h"

static Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    isMallocSuccesful(node);
    return node;
}

static Linked_list *create_linked_list(int *values, int length)
{
    Node *first = create_node(values[0]);
    ;
    Node *tail = first;

    for (int i = 1; i < length; i++)
    {
        tail->next = create_node(values[i]);
        tail = tail->next;
    }

    Linked_list *list = malloc(sizeof(Linked_list));
    list->head = first;
    list->tail = tail;
    list->length = length;
    return list;
}

static void append_node(Node *a, Node *b)
{
    a->next = b;
}

// linkes the nodes like this a -> b -> c
static void append_node_between(Node *a, Node *b, Node *c)
{
    a->next = b;
    b->next = c;
}

static Node *get_node_at(Linked_list *list, int index)
{
    if(index == 0){
        return list->head;
    }
    Node *temp;
    Node *head = list->head;
    for (int i = 0; i <= index; i++)
    {
        temp = head;
        head = head->next;
    }
    return temp;
}

Linked_list *linked_list_create(int *values, int length)
{
    return create_linked_list(values, length);
}

void linked_list_add_array(Linked_list *a, int *values, int length)
{
    Linked_list *b = create_linked_list(values, length);
    a->tail->next = b->head;
    a->tail = b->tail;
    a->length += b->length;
    free(b);
}

void linked_list_add(Linked_list *list, int value)
{
    Node *newNode = create_node(value);
    append_node(list->tail, newNode);
    list->tail = newNode;
    list->length++;
}
void linked_list_add_at(Linked_list *list, int index, int value)
{
    if (index == 0)
    {
        Node *temp = create_node(value);
        temp->next = list->head;
        list->head = temp;
    }
    else
    {
        Node *b = create_node(value);
        Node *a = get_node_at(list, index - 1);
        Node *c = a->next;
        list->length++;
        append_node_between(a, b, c);
    }
}

int linked_list_get_at(Linked_list *list, int index)
{
    return get_node_at(list, index)->value;
}

void linked_list_print(Linked_list *list)
{
    Node *temp;
    Node *head = list->head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        printf("%d\n", temp->value);
    }
}