#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Core Loop and Execution */
void shell_loop(char *prog_name);
int execute(char **args, char *prog_name, int counter);

/* Helper Functions */
char **tokenize(char *line);
void free_args(char **args);
int _strlen(char *s);
void print_error(char *prog_name, int counter, char *cmd);

/* PATH and Environment */
char *_get_path(char *command);
char *_getenv(const char *name);

/* Built-ins */
int handle_builtin(char **args, char *line);

#endif /* SHELL_H */
