#include "main.h"

/**
 * _strncmp - compare two strings up to n characters
 * @str1: first string
 * @str2: second string
 * @num: the maximum number of characters to compare
 * Return: 0 if the strings are equal up to the first n characters
 * or a negative value if str1 is less than str2
 * or a positive value if str1 is greater than str2
 */
int _strncmp(const char *str1, const char *str2, size_t num)
{
	while (num > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		num--;
	}

	if (num == 0)
		return (0);
	else
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strdup - duplicate a string
 * @src_string: the string to duplicate
 * Return: a pointer to the newly allocated duplicate string
 * or NULL if memory allocation fails
 */
char *_strdup(char *src_string)
{
	int len = 0;
	char *dup_string = NULL;

	if (src_string == NULL)
		return (NULL);

	len = _strlen(src_string);
	dup_string = malloc(len + 1);

	if (dup_string != NULL)
	{
		_strcpy(dup_string, src_string);
	}

	return (dup_string);
}
