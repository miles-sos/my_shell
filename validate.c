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
