#include "shell.h"

/**
 * _strlen - Returns length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * print_error - Custom error printer to match sh
 * @prog_name: argv[0]
 * @counter: line count
 * @cmd: failed command
 */
void print_error(char *prog_name, int counter, char *cmd)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, counter, cmd);
}
