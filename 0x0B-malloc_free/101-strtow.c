#include "main.h"
#include <stdlib.h>

/**
 * count_word - Count the number of words in a string
 * @s: The string
 *
 * Return: The number of words
 */
int count_word(char *s)
{
	int i, flag = 0, words = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			words++;
		}
	}

	return words;
}

/**
 * strtow - Split a string into words
 * @str: The string to split
 *
 * Return: Pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str)
{
	int i, j, k, len, words;
	char **matrix;
	int start = 0, end = 0, c = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c != 0)
			{
				end = i;
				matrix[k] = malloc(sizeof(char) * (c + 1));
				if (matrix[k] == NULL)
				{
					for (j = 0; j < k; j++)
						free(matrix[j]);
					free(matrix);
					return (NULL);
				}

				for (j = start, k = 0; j < end; j++, k++)
					matrix[i][k] = str[j];
				matrix[k][k] = '\0';
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
