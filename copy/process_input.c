#include "main.h"

/**
 * process_input - handles the execution of
 * commands in the shell
 * @toks: first token
 * @toks_arr: array of tokens
 * @env: environment variable
 * Return: flag 1 after execution
 */
int process_input(char *toks, char **toks_arr, char **env, char **av)
{
	struct stat st;
	pid_t pid;
	int status;
	char *path = NULL, *file_path = NULL;
	int flag = 0;

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
		path = get_path(env);
		file_path = tok_path(path, toks);
		if (!file_path)
			perror("command not found");
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
		free(file_path);
	}
	return (flag);
}
