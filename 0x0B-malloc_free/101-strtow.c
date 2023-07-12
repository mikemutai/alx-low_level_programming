#include <stdlib.h>
#include "main.h"

/**
 * count_word - counts the number of words in a string
 * @s: pointer to the string
 *
 * Return: Number of words in the string
 */
int count_word(char *s)
{
	int flag = 0, w = 0, c;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * strtow - splits a string into individual words
 * @str: pointer to the string
 *
 * Return: Pointer to an array of strings, or NULL if fail.
 */
char **strtow(char *str)
{
	int i, len = 0, c = 0, k = 0, start, end;
	char **matrix, *tmp;

	while (str[len] != '\0')
		len++;

	if (len == 0)
		return (NULL);

	matrix = malloc(sizeof(char *) * (count_word(str) + 1));

	if (matrix == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = malloc(sizeof(char) * (c + 1));
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
		{
			start = i;
		}
	}

	matrix[k] = NULL;
	return (matrix);
}
