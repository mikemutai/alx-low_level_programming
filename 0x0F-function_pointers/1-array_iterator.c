#include <stdio.h>
#include <stddef.h> /* Add this line to include size_t definition */
#include "function_pointers.h" /* Add other necessary includes if needed */

/**
 * array_iterator - prints each array element on a new line
 * @array: array
 * @size: how many elements to print
 * @action: pointer to print in regular or hex
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
    unsigned int i;

    if (array == NULL || action == NULL)
        return;

    for (i = 0; i < size; i++)
    {
        action(array[i]);
    }
}
