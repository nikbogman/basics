#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} node_t;

void add_back(node_t *head, int data)
{
    node_t *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = (node_t *)malloc(sizeof(node_t));
    last->next->data = data;
    last->next->next = NULL;
}

void add_front(node_t **head, int data)
{
    node_t *first = (node_t *)malloc(sizeof(node_t));
    first->data = data;
    first->next = *head;
    *head = first;
}

int remove_back(node_t *head)
{
    int removed = -1;
    if (head == NULL)
    {
        return removed;
    }
    if (head->next == NULL)
    {
        removed = head->data;
        free(head);
        return removed;
    }

    node_t *last = head;
    while (last->next->next != NULL)
    {
        last = last->next;
    }
    removed = last->next->data;
    free(last->next);
    last->next = NULL;
    return removed;
}

int remove_front(node_t **head)
{
    int removed = -1;
    node_t *first = *head;
    if (first->next == NULL)
    {
        removed = first->data;
        free(first);
        return removed;
    }
    removed = first->data;
    *head = first->next;
    free(first);
    return removed;
}

void print(node_t *head)
{
    node_t *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int at(node_t *head, int idx)
{
    node_t *current = head;
    int i = 0;
    while (i < idx)
    {
        current = current->next;
        if (current == NULL)
        {
            return -1;
        }
        i++;
    }
    return current->data;
}

int first(node_t *head)
{
    if (head == NULL)
    {
        return -1;
    }
    return head->data;
}

int last(node_t *head)
{
    node_t *last = head;
    if (head == NULL)
    {
        return -1;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    return last->data;
}

int main()
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->next = NULL;
    head->data = NULL;

    add_back(head, 1);
    add_back(head, 2);
    add_back(head, 3);

    add_front(&head, 4);
    add_front(&head, 5);

    print(head);

    free(head);
    return 0;
}