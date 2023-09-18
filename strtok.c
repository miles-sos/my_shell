#include "main.h"

/**
 * _strtok - Tokenizes  array of strings
 * @str: string variable
 * @delim: delimiter
 * Return: return the value of "tok_St" on success
 */
char *_strtok(char *str, const char *delim)
{
	char *tok_St;
	char *tok_End;
	static char *next_Tok;

	if (str != NULL)
		next_Tok = str;

	if (next_Tok == NULL)
		return (NULL);

	tok_St = next_Tok;
	/* Find the end of the tok_end */
	tok_End = _strpbrk(next_Tok, delim);

	if (tok_End != NULL)
	{
		*tok_End = '\0';
		next_Tok = tok_End + 1;
	}
	else
	{
		next_Tok = NULL;
	}
	return (tok_St);
}

/**
 * _strpbrk - search a string for any of a set of bytes
 * @strGet: string to searched through
 * @strSET: string that has a byte to be located
 *
 * Return: a pointer to the byte in strGet that matches
 * one of the bytes in strSET, or NULL if not found.
 */
char *_strpbrk(const char *strGet, const char *strSET)
{
	while (*strGet != '\0')
	{
		const char *str_set = strSET;

		while (*str_set != '\0')
		{
			/* If condition is true "strGet" is type cast char* */
			if (*strGet == *str_set)
				return ((char *)strGet);
			str_set++;
		}
		strGet++;
	}
	return (NULL);
}
