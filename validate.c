#include "main.h"

/**
 * check_read_chars - handles EOF or CTRL + D
 * @num_chars: no of characters read from getline
 * @buffer: the buffer containing the read_chars
 * Return: void
 */
void check_read_chars(ssize_t num_chars, char *buffer)
{
	if (num_chars == -1)
	{
		_putstr("\n");
		fflush(stdout);
		free(buffer);
		exit(1);
	}
}

/**
 * check_newline_char - checks if
 * buffer has ONLY newline character
 * @buffer: the buffer holding read chars
 * Return: 1 if true, nothing otherwise
 */
int check_newline_char(char *buffer)
{
	if (buffer[0] == '\n')
	{
		fflush(stdout);
		return (1);
	}
}

/**
 * replace_newline - replaces \n with \0
 * @buffer: the buffer containing the read_chars
 * @read_chars: no of characters read
 * Return: void
 */
void replace_newline(char *buffer, ssize_t read_chars)
{
	if (buffer[read_chars - 1] == '\n')
	{
		buffer[read_chars - 1] = '\0';
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
		tokens[i] = malloc((_strlen(token) + 1) * sizeof(char));
		strcpy(tokens[i], token);
		i++;
		token = _strtok(NULL, del);
	}
	tokens[i] = NULL;
	return (tokens);
}

// tokens_arr["ls", "-l", " "];
// tokens_arr[num_of_toks - 1] = '\0';
