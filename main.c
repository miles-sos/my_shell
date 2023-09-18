#include "main.h"

/**
 * main - entry point to program
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 * Return: 0 on SUCCESS
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	ssize_t read_chars = 0;
	char *buffer = NULL, *cpy_buffer = NULL, **toks_arr = NULL, **tokens = NULL;
	const char *delim = " \n";
	size_t buff_size = 0;
	int num_toks = 0, flag = 0;

	for (;;) /*while(1)*/
	{
		is_interactive(); /*runs the prompt in interactive mode*/
		read_chars = _getline(&buffer, &buff_size, stdin);
		check_read_chars(read_chars, buffer);
		if (check_newline_char(buffer) == 1)
			continue;
		replace_newline(buffer, read_chars); /*change \n to \0*/
		cpy_buffer = strdup(buffer); /*keep a copy of the buffer*/
		num_toks = get_num_tokens(cpy_buffer, delim); /*count no of tokens*/
		tokens = allocMemTokens(num_toks, buffer, cpy_buffer); /*allocate memory*/
		toks_arr = tokenize_buffer(tokens, buffer, delim); /*tokenize the input*/

		exit_shell(toks_arr, buffer, cpy_buffer, tokens, num_toks); /*exit*/

		if (strcmp(toks_arr[0], "cd") == 0) /*cd command*/
		{
			change_dir(toks_arr, env);
			free_all(cpy_buffer, tokens, toks_arr, num_toks);
			continue;
		}
		flag = process_input(toks_arr[0], toks_arr, env, argv);
		free_all(cpy_buffer, tokens, toks_arr, num_toks);
		if (flag == 1)
			continue;
	}
	free(buffer);
	return (0);
}
