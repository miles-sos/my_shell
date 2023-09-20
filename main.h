#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define CWD_SIZE 100

/*Defined in shell.c*/
int _putchr(char ch);
int _putstr(char *str);
void prompt(void);
void is_interactive(void);
void check_read_chars(ssize_t num_chars, char *buffer);
int check_newline_char(char *buffer);
void replace_newline(char *buffer, ssize_t read_chars);
char **alloc_mem_for_tokens(int num_toks);
char **allocMemTokens(int nt, char *buff, char *cpy_buff);
int check_ctrlD(ssize_t n);
int get_num_tokens(char *buffer, const char *delim);
char **tokenize_buffer(char **tokens, char *buffer, const char *del);
int process_input(char *toks, char **toks_arr, char **env, char **av);
char *get_pg_name(char **av);

void free_toks_array(char **toks, int num_toks);
void free_all(char *cpy, char **toks_arr, char **toks, int nt);
int check_stat(char *command, struct stat v);
void execute_command(char *toks_first, char **toks_arr, char **env);
char *get_path(char **env);
char *tok_path(char *path, char *command);
char *get_env_var(char **env, char *var, int var_len);
int _setenv(char *var, char *value, int overwrite, char **env);


void exit_shell(char **toks, char *bu, char *cp, char **toks_m, int nt);
int builtin(char **toks_arr, char **env, char *cp, char **toks_m, int nt);
void change_dir(char **toks, char **env);
int _getc(FILE *input);
ssize_t _getline(char **_get, size_t *nget, FILE *input);


char *_strpbrk(const char *strGet, const char *strSET);
char *_strtok(char *str, const char *delim);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *str1, const char *str2);
char *_strstr(char *main_str, char *sub_str);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *str1, const char *str2, size_t num);
char *_strdup(char *src_string);

#endif /* MAIN_H */
