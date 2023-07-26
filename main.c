#include "main.h"

/**
 * main - Simple shell program that takes user input
 * @ac: The number of command-line arguments (unused).
 * @av: An array of command-line argument strings (unused).
 * @env: An array of environment variables.
 * Return: Returns 0 on successful execution.
 */
int main(int ac, char **av, char **env)
{
	char *buf = NULL;
	size_t buf_size = 0;
	char **argums = NULL;
	pid_t pid;
	int status, x_character;
	int inter = 1;

	(void)ac;
	(void)av;
	if (!isatty(STDIN_FILENO))
	{
		inter = 0;
	}
	while (1)
	{
		if (inter)
		{
			write(1, "$ ", 2);
		}
		x_character = getline(&buf, &buf_size, stdin);
		if (x_character == -1)
		{
			if (inter)
			{
				write(1, "\n", 1);
			}
			break;
		}
		argums = str_split(buf, " \t\n");
		if (compare_string_strcmp(argums[0], "exit") == 0)
		{
			tok_free(argums);
			break;
		}
		pid = fork();
		if (pid == 0)
		{
			if (comnd_exec(argums, env) == -1)
			{
				exit(EXIT_FAILURE);
			}

			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
			tok_free(argums);
		}
	}
	free(buf);
	return (0);
}

