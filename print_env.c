#include "shell.h"

/**
 * print_env - Prints the built-in env
 *
 * Return: Void
 */

void print_env(void)
{
	int i = 0, j = 0;
	char environ;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}

		if (j != 0)
			_putchar('\n');
		i++;
	}
}
