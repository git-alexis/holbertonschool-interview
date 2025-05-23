#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *
 * @head: pointer to pointer of the first node
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *current = *head;
    int index = 0, length = 0, midle;

    if (!head || !(*head))
        return (1);

    while (current)
    {
        length++;
        current = current->next;
    }

    midle = length / 2;
    int values[midle];

    current = *head;
    while (index < midle)
    {
        values[index] = current->n;
        current = current->next;
        index++;
    }

    if (length % 2 != 0)
        current = current->next;

    index--;
    while (current)
    {
        if (current->n != values[index])
            return (0);
        current = current->next;
        index--;
    }

    return (1);
}
