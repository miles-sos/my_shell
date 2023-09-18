#include "main.h"

/**
 * exit_shell - implements the exit builtin
 * @toks: array of tokens
 * Return: 1 on success, 0 in failure
 */
int exit_shell(char **toks, char *bu, char *cp, char **toks_m, int nt)
{
	if (strcmp(toks[0], "exit") == 0)
	{
		free_all(cp, toks_m, toks, nt);
		free(bu);
		return (1);
	}
	return (0);
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
