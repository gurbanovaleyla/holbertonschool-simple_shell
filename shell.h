#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Function prototypes */
void run_shell(char **argv);
char **tokenize(char *line);
void execute(char **args, char **argv);
void free_args(char **args);

#endif /* SHELL_H */
