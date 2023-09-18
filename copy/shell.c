#include "main.h"

/**
 * _putchar - prints a char to the stdout
 * @ch: character to be printed
 * Return: no of char printed
 */
int _putchr(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _putstr - prints a string to the stdout
 * @str: string to be printed
 * Return: number of characters printed
 */
int _putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		_putchr(str[i]);
		i++;
	}
	return (i);
}

/**
 * prompt - display the shell prompt
 * Return: void
 */
void prompt(void)
{
	_putstr("shell$ ");
}

/**
 * is_interactive - prompts user
 * else, takes inputs via pipes
 * Return: void
 */
void is_interactive(void)
{
	if (isatty(STDIN_FILENO))
	{
		prompt();
	}
}

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
	token = strtok(buffer, delim);
	while (token)
	{
		i++;
		token = strtok(NULL, delim);
	}
	return (i);
}

/**
 * tokenize_buffer - break the string read to tokens
 * @tokens: empty array of strings
 * @buffer: string to be tokenized
 * Return: array of tokens
 */
char **tokenize_buffer(char **tokens, char *buffer, const char *del)
{
	char *token = NULL;
	int i = 0;

	token = strtok(buffer, del);
	while (token)
	{
		tokens[i] = malloc((strlen(token) + 1) * sizeof(char));
		strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, del);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * free_toks_array - frees the tokens in the array
 * @toks_arr: array of strings(tokens)
 * @num_toks: num of tokens used in the loop
 * Return: void
 */
void free_toks_array(char **toks, int num_toks)
{
	int i;
	for (i = 0; i < num_toks; i++)
	{
		free(toks[i]);
	}
}

/**
 * freeMemInBuiltin - frees all memory allocations
 * in command is a builtin function
 * @cpy: copy of the buffer to be freed
 * @tokens: tokens array to be freed
 * Return: void
 */
void free_all(char *cpy, char **toks_arr, char **toks, int nt)
{
	free_toks_array(toks, nt);
	free(cpy);
	free(toks_arr);
}
