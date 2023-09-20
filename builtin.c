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

	if (_strcmp(toks[0], "exit") == 0)
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
	char *var = NULL, *path = NULL;
	int i = 0;

	if (toks[1] == NULL || _strcmp(toks[1], "") == 0)
	{
		var = "HOME=";
		path = get_env_var(env, var, _strlen(var));
		path = _strstr(path, var);
		path += _strlen(var);
		if (path)
			chdir(path);
	}
	else if (_strcmp(toks[1], "-") == 0)
	{
		var = "OLDPWD=";
		path = get_env_var(env, var, _strlen(var));
		path = _strstr(path, var);
		path += _strlen(var);
		if (path)
			chdir(path);
	}
	else if (chdir(toks[1]) == -1)
	{
		perror("unknown");
	}
}

/**
 * _setenv - sets/updates an environment variable
 * @var: variable name
 * @value: value to be set
 * @overwrite: choose to update or NOT
 * @env: environment variable collection
 * Return: 0 if successful, -1 on failure
 */
int _setenv(char *var, char *value, int overwrite, char **env)
{
	char *_var_exist = NULL, *env_var = NULL;

	if (var == NULL || value == NULL || strchr(var, '=') != NULL)
	{
		return (-1);
	}
	_var_exist = get_env_var(env, var, _strlen(var));
	if (_var_exist != NULL) /*EXISTS*/
	{
		if (overwrite)
		{
			env_var  = malloc(_strlen(var) + _strlen(value) + 2);
			if (env_var == NULL)
				return (-1);

			_strcpy(env_var, var);
			_strcat(env_var, "=");
			_strcat(env_var, value);

			/*env_var[_strlen(env_var)] = '\0';*/
			putenv(env_var);
			free(env_var);
		}
		else
			return (0);
	}
	else /*NOT EXIST*/
	{
		env_var = malloc(_strlen(var) + _strlen(value) + 2);
		if (env_var == NULL)
			return (-1);

		_strcpy(env_var, var);
		_strcat(env_var, "=");
		_strcat(env_var, value);
		if (putenv(env_var) != 0)
			return (-1);
		free(env_var);
	}
	return (0);
}
