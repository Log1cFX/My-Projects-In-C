#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "util.h"

// static functions //

/// @brief creates a node of a generic type variable
/// @param value a void pointer, pointing to a variable
/// @return a pointer to a node allocated in the heap, with the var struct in value
static Node *create_node(var *value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    isMallocSuccesful(node);
    return node;
}

/// @brief creates a linked list with given array of generic type variables
/// @param values array of void pointers, pointing to variables
/// @param length length of the array
/// @return an initialized LinkedList struct
static LinkedList *create_linked_list(var *values, int length)
{
    Node *first = create_node(&values[0]);
    Node *tail = first;

    for (int i = 1; i < length; i++)
    {
        tail->next = create_node(&values[i]);
        tail = tail->next;
    }

    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = first;
    list->tail = tail;
    list->length = length;
    return list;
}

/// @brief linkes the nodes like this a -> b
/// @param a
/// @param b
static void append_node(Node *a, Node *b)
{
    a->next = b;
}

/// @brief linkes the nodes like this a -> b -> c
/// @param a
/// @param b
/// @param c
static void append_node_between(Node *a, Node *b, Node *c)
{
    a->next = b;
    b->next = c;
}

/// @brief gets the node at the given index
/// @param list 
/// @param index 
/// @return pointer to the node at the index
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

/// @brief creates an empty linked list
/// @return an allocated LinkedList struct with all the values being 0
LinkedList *LinkedList_CreateEmptyList()
{
    // LinkedList *list = calloc(1, sizeof(LinkedList));
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

/// @brief creates a linked list with given array of generic type variables
/// @param values array of pointers to initialized var structs
/// @param length length of the array
/// @return an initialized LinkedList struct
LinkedList *LinkedList_Create(var *values, int length)
{
    return create_linked_list(values, length);
}


void LinkedList_AddArray(LinkedList *a, var *values, int length)
{
    LinkedList *b = create_linked_list(values, length);
    a->tail->next = b->head;
    a->tail = b->tail;
    a->length += b->length;
    free(b);
}

void LinkedList_Add(LinkedList *list, var *value)
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

void LinkedList_AddAt(LinkedList *list, var *value, int index)
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

var *LinkedList_GetAt(LinkedList *list, int index)
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
    genericType(int)
    Node *temp;
    Node *head = list->head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        printf("%d\n", Type_get_int(temp->value));
    }
}

void LinkedList_PrintEvery1000th(LinkedList *list)
{
    Node *temp;
    Node *head = list->head;
    int i = 0;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        i++;
        if (i % 1000 == 0)
        {
            printf("%d\n", temp->value);
            i = 0;
        }
    }
    printf("%d\n", list->tail->value);
}