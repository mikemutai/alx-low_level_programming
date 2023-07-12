#include "main.h"
#include <stdio.h>
#include <stdlib.h>

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

	if (str == NULL || *str == '\0')
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	words = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			words++;
	}

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	j = 0;
	for (i = 0; i < len && j < words; i++)
	{
		if (str[i] != ' ')
		{
			k = i;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			matrix[j] = malloc(sizeof(char) * (i - k + 1));
			if (matrix[j] == NULL)
			{
				for (j = j - 1; j >= 0; j--)
					free(matrix[j]);
				free(matrix);
				return (NULL);
			}
			k = 0;
			while (k < (i - k))
			{
				matrix[j][k] = str[k + j];
				k++;
			}
			matrix[j][k] = '\0';
			j++;
		}
	}
	matrix[j] = NULL;

	return (matrix);
}
