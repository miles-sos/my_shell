#include "main.h"

/**
 * free_toks_array - frees the tokens in the array
 * @toks: array of strings(tokens)
 * @num_toks: num of tokens used in the loop
 * Return: void
 */
void free_toks_array(char **toks, int num_toks)
{
	int i;

	for (i = 0; i < num_toks; i++)
	{
		free(toks[i]);
	}
}

/**
 * free_all - frees all memory allocations
 * in command is a builtin function
 * @cpy: copy of the buffer to be freed
 * @toks_arr: the toks_arr memory
 * @toks: array of tokens to be freed
 * @nt: number of tokens
 * Return: void
 */
void free_all(char *cpy, char **toks_arr, char **toks, int nt)
{
	free_toks_array(toks, nt);
	free(cpy);
	free(toks_arr);
}
