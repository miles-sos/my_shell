#include "main.h"

/**
 * _putchr - prints a char to the stdout
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
	char store_cwd[CWD_SIZE];
	char *cwd = NULL;

	if (getcwd(store_cwd, sizeof(store_cwd)) != NULL)
	{
		cwd = getcwd(store_cwd, sizeof(store_cwd));
		_putstr(cwd);
	}
	_putstr("$ ");
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
