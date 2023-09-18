#include "main.h"

/**
 * _strlen - gets the length of a string
 * @str: string parsed
 * Return: length of the string excluding
 * the null character
 */
int _strlen(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
