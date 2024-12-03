#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "util.h"

// static functions //
static Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    isMallocSuccesful(node);
    return node;
}

static LinkedList *create_linked_list(int *values, int length)
{
    Node *first = create_node(values[0]);
    Node *tail = first;

    for (int i = 1; i < length; i++)
    {
        tail->next = create_node(values[i]);
        tail = tail->next;
    }

    LinkedList *list = malloc(sizeof(LinkedList));
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

static Node *get_node_at(LinkedList *list, int index)
{
    if (index == 0)
    {
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

// global Functions //
LinkedList *LinkedList_CreateEmptyList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

LinkedList *LinkedList_Create(int *values, int length)
{
    return create_linked_list(values, length);
}

void LinkedList_AddArray(LinkedList *a, int *values, int length)
{
    LinkedList *b = create_linked_list(values, length);
    a->tail->next = b->head;
    a->tail = b->tail;
    a->length += b->length;
    free(b);
}

void LinkedList_Add(LinkedList *list, int value)
{
    Node *newNode = create_node(value);
    if (list->length == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        append_node(list->tail, newNode);
        list->tail = newNode;
    }
    list->length++;
}

void LinkedList_AddAt(LinkedList *list, int index, int value)
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

int LinkedList_GetAt(LinkedList *list, int index)
{
    return get_node_at(list, index)->value;
}

void LinkedList_DeleteAt(LinkedList *list, int index)
{
    if (index == 0)
    {
        Node *temp = list->head;
        list->head = list->head->next;
        list->length--;
        free(temp);
    }
    else
    {
        Node *a = get_node_at(list, index - 1);
        Node *temp = a->next;
        Node *b = a->next->next;
        append_node(a, b);
        list->length--;
        free(temp);
    }
}

void LinkedList_Print(LinkedList *list)
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