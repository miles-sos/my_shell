#include "main.h"

/**
 * get_num_tokens - gets the no of tokens in string
 * @buffer: the string passed
 * @delim: the delimiter used to tokenize string
 * Return: no of tokens
 */
int get_num_tokens(char *buffer, const char *delim)
{
	int i = 0;
	char *token = NULL;

	token = _strtok(buffer, delim);
	while (token)
	{
		i++;
		token = _strtok(NULL, delim);
	}
	return (i);
}

/**
 * allocMemTokens - allocate memory for the array of
 * strings (i.e. before tokenization)
 * @nt: number of tokens
 * @buff: buffer
 * @cpy_buff: copy of buffer
 * Return: pointer to array of strings memory
 */
char **allocMemTokens(int nt, char *buff, char *cpy_buff)
{
	char **tokens = NULL;

	if (nt)
	{
		tokens = malloc((nt + 1) * sizeof(char *));
		if (!tokens)
		{
			perror("Failed memory Allocation");
			free(buff);
			free(cpy_buff);
			return (NULL);
		}
		return (tokens);
	}
}

/**
 * tokenize_buffer - break the string read to tokens
 * @tokens: empty array of strings
 * @buffer: string to be tokenized
 * @del: delimiter
 * Return: array of tokens
 */
char **tokenize_buffer(char **tokens, char *buffer, const char *del)
{
	char *token = NULL;
	int i = 0;

	token = _strtok(buffer, del);
	while (token)
	{
		if (_strlen(token) > 0)
		{
			tokens[i] = malloc((_strlen(token) + 1) * sizeof(char));
			_strcpy(tokens[i], token);
			i++;
		}
		token = _strtok(NULL, del);
	}
	tokens[i] = NULL;

	return (tokens);
}
