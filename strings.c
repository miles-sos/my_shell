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

/**
 * _strcpy - copy strings from one
 * location to another
 * @dest: the destination
 * @src: the source
 * Return: pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if eq, -1 or 1 if otherwise
 */
int _strcmp(const char *str1, const char *str2)
{
	int i;

	if (str1 == NULL || str2 == NULL)
	{
		return (-1);
	}

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] > str2[i])
			return (1);
		i++;
	}

	if (str1[i] == '\0' && str2[i] != '\0')
		return (-1);
	else if (str1[i] != '\0' && str2[i] == '\0')
		return (1);

	return (0);
}

/**
 * _strstr - check for a substring in a string
 * @main_str: main string to be searched in
 * @sub_str: sub-string to look for
 * Return: pointer to the position where sub_str
 * was found or NULL if otherwise
 */
char *_strstr(char *main_str, char *sub_str)
{
	char *b_str = NULL;
	char *s_str = NULL;

	if (*sub_str == '\0')
		return ((char *)main_str);

	while (*main_str != '\0')
	{
		b_str = main_str;
		s_str = sub_str;

		while (*s_str != '\0' && *b_str == *s_str)
		{
			b_str++;
			s_str++;
		}
		if (*s_str == '\0')
			return (main_str);

		main_str++;
	}
	return (NULL);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: pointer to the destination
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len, i;

	if (dest == NULL || src == NULL)
	{
		return (dest);
	}

	dest_len = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return (dest);
}
