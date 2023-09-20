#include "main.h"

/**
 * check_stat - check if program exists
 * @command: the command to check
 * @v: struct stat pointer
 * Return: -1 on FAILURE, 0 on SUCCESS
 */
int check_stat(char *command, struct stat v)
{
	if (stat(command, &v) == 0)
		return (0);
	else
		return (-1);
}

/**
 * execute_command - executes user's command
 * @toks_first: first token in the toks array
 * @toks_arr: array of tokens
 * @env: environment variable array
 * Return: -1 on FAILURE, void on SUCCESS
 */
void execute_command(char *toks_first, char **toks_arr, char **env)
{
	if (execve(toks_first, toks_arr, env) == -1)
	{
		perror(toks_first);
		exit(1);
	}
}

/**
 * get_path - adds command to each PATH
 * @env: environment variables
 * Return: pointer to PATH
 */
char *get_path(char **env)
{
	char *find = "PATH=", *cpy_path = NULL;
	char *path = NULL, *delim = ":";

	path = get_env_var(env, find, strlen(find));
	cpy_path = strstr(path, find);
	cpy_path += strlen(find);
	return (cpy_path);
}

/**
 * get_env_var - fetch desired environment variable
 * @env: environment variables
 * @var: lookup varible
 * @var_len: length of lookup variable
 * Return: pointer to lookup var OR NULL
 */
char *get_env_var(char **env, char *var, int var_len)
{
	int i = 0;

	while (env[i])
	{
		if (_strncmp(env[i], var, _strlen(var)) == 0)
		{
			return (env[i]);
		}
		i++;
	}
	return (NULL);
}

/**
 * tok_path - split the PATH, append the /
 * append the command and search if file exists
 * @path: PATH to be tokenized
 * @command: argv[0] to search
 * Return: file path if found or NULL
 */
char *tok_path(char *path, char *command)
{
	char *pathtok = NULL, *file_path = NULL;
	char *delim = ":";
	char *copy_path = NULL;
	size_t file_path_len;

	copy_path = _strdup(path);

	pathtok = _strtok(copy_path, delim);
	while (pathtok)
	{
		file_path_len = _strlen(pathtok) + 1 + _strlen(command) + 1;
		file_path = malloc(file_path_len);
		if (!file_path)
		{
			perror("Memory allocation failed");
			free(copy_path);
			return (NULL);
		}
		_strcpy(file_path, pathtok);
		_strcat(file_path, "/");
		_strcat(file_path, command);

		if (access(file_path, X_OK) == 0)
		{
			free(copy_path);
			return (file_path);
		}

		free(file_path);
		pathtok = _strtok(NULL, delim);
	}
	free(copy_path);
	return (NULL);
}
