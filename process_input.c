#include "main.h"

/**
 * process_input - handles the execution of
 * commands in the shell
 * @toks: first token
 * @toks_arr: array of tokens
 * @env: environment variable
 * @av: argument vector
 * Return: flag 1 after execution
 */
int process_input(char *toks, char **toks_arr, char **env, char **av)
{
	(void **)av;
	struct stat st;
	pid_t pid;
	int status, flag = 0;
	char *path = NULL, *file_path = NULL, *pg_name = NULL;

	/*execute the program - step 1 (STAT)*/
	if (check_stat(toks, st) == 0)
	{
		pid = fork();
		if (pid < 0)
			perror("Fork failed");

		if (pid == 0)
			execute_command(toks, toks_arr, env);
		else
			wait(&status);
	}
	else
	{
		pg_name = get_pg_name(av);
		path = get_path(env);
		file_path = tok_path(path, toks);
		if (!file_path)
			perror(pg_name);
		else
		{
			pid = fork();
			if (pid == 0)
				execute_command(file_path, toks_arr, env);
			else
			{
				wait(&status);
				flag = 1;
			}
		}
		free(file_path), free(pg_name);
	}
	return (flag);
}

/**
 * get_pg_name - get the program name
 * to be used in the error prompt
 * @av: argument vector
 * Return: program name
 */
char *get_pg_name(char **av)
{
	char *error = NULL;
	int program_name_len = 0;

	program_name_len = _strlen(av[0]);

	error = malloc(sizeof(char) * program_name_len + 1);
	if (!error)
	{
		perror("Failed memory allocation");
		return (NULL);
	}
	_strcpy(error, av[0]);
	return (error);
}
