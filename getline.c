#include "main.h"

/**
 * _getline - handles getting chars from a FILE stream
 * @_get: Buffer that stores the chars from a stream
 * @nget: The size of buffer
 * @input: The FILE stream either from stdin or file
 * Return: The number of chars written on success
 */
ssize_t _getline(char **_get, size_t *nget, FILE *input)
{
	char *_getcpy, *updategetcpy;
	int ch;
	size_t i = 0;

	if (*_get == NULL || *nget == 0)
	{
		*nget = 10;
		*_get = (char *)malloc(*nget);
		if (*_get == NULL)
		{
			perror("_get memory allocation failed");
			return (-1);
		}
	}

	_getcpy = *_get;

	while ((ch = _getc(input)) != EOF)
	{
		if (i >= *nget - 1)
		{
			*nget *= 2; /*Double the size of nget if true*/
			updategetcpy = (char *)realloc(_getcpy, *nget); /*Update memory*/
			if (updategetcpy == NULL)
			{
				perror("realloc");
				return (-1);
			}
			_getcpy = updategetcpy;
			*_get = _getcpy; /*Update the original _get*/
		}

		_getcpy[i++] = (char)ch; /*type casting*/
		if (ch == '\n')
			break;
	}
	return (i);
}


/**
 * _getc - handles geting character
 * @input: Either from "file" or "standard input"
 * Return: The value of ch on success.
*/
int _getc(FILE *input)
{
	char ch;
	ssize_t line_R;

	if (input == NULL)
		return (EOF);

	line_R = read(fileno(input), &ch, 1);

	if (line_R != 1)
		return (EOF);
	return ((int)ch);
}
