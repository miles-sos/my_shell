#include "main.h"

/**
 * exit_shell - implements the exit builtin
 * @toks: array of tokens
 * @bu: buffer used with _getline
 * @cp: copy of the buffer
 * @toks_m: tokens_memory
 * @nt: number of tokens
 * Return: 1 on success, 0 in failure
 */
void exit_shell(char **toks, char *bu, char *cp, char **toks_m, int nt)
{
	int exit_status = 0;

	if (strcmp(toks[0], "exit") == 0)
	{
		if (toks[1]) /*exit with argument passed*/
		{
			exit_status = atoi(toks[1]);
			free_all(cp, toks_m, toks, nt);
			free(bu);
			exit(exit_status);
		}
		else /*exit without argument*/
		{
			free_all(cp, toks_m, toks, nt);
			free(bu);
			exit(exit_status);
		}
	}
}

/**
 * change_dir - implements the cd builtin
 * @toks: array of tokens
 * @env: env_var to obtain the "HOME=" var
 * Return: void
 */
void change_dir(char **toks, char **env)
{
	char *home = "HOME=", *path = NULL;

	if (toks[1] == NULL) /*move to home dir*/
	{
		path = get_env_var(env, home, strlen(home));
		path = strstr(path, home);
		path += strlen(home);
		if (path)
			chdir(path);
	}
	else
		chdir(toks[1]);
}
