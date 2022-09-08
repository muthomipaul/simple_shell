#ifndef MAIN_H
#define MAIN_H
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

typedef struct data
{
        char **av;
        char *input;
        char **args;
        int status;
        int counter;
        char **_environ;
        char *pid;
} data_shell;

char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);
char *error_path_126(data_shell *datash);
char *error_env(data_shell *datash);

void aux_help_exit(void);
void aux_help_general(void);
void aux_help_unsetenv(void);
void aux_help_setenv(void);
void aux_help_env(void);
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

typedef struct sep_list_s
{
        char separator;
        struct sep_list_s *next;
} sep_list;

typedef struct line_list_s
{
        char *line;
        struct line_list_s *next;
} line_list;

void free_line_list(line_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_sep_list(sep_list **head);
sep_list *add_sep_node_end(sep_list **head, char sep);

typedef struct r_var_list
{
        int len_var;
        char *val;
        int len_val;
        struct r_var_list *next;
} r_var;

void free_rvar_list(r_var **head);
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval);

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);

int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);


#endif
