#include "main.h"

/**
 * main - Simple shell program that takes user input
 * @ac: The number of command-line arguments (unused).
 * @av: An array of command-line argument strings (unused).
 * @env: An array of environment variables.
 * Return: Returns the exit status of the last command executed.
 */
int main(int ac, char **av, char **env)
{
	char *buf = NULL;
	size_t buf_size = 0;
	char **argums = NULL;
	pid_t pid;
	int status = 0; 
	int x_character;
	int inter = 1;

	(void)ac;
	(void)av;

	if (!isatty(STDIN_FILENO))
		inter = 0;

	while (1)
	{
		if (inter)
			write(1, "$ ", 2);

		x_character = getline(&buf, &buf_size, stdin);
		if (x_character == -1)
		{
			if (inter)
				write(1, "\n", 1);
			break;
		}

		argums = str_split(buf, " \t\n");
		if (!argums || argums[0] == NULL)
		{
			free(buf);
			if (argums)
			{
				tok_free(argums);
			}
			exit(EXIT_SUCCESS);
		}
		if (compare_string_strcmp(argums[0], "exit") == 0)
		{
			tok_free(argums);
			break;
		}

		pid = fork();
		if (pid == 0)
		{
			comnd_exec(argums, env);
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("Fork error");
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status)) {
				status = WEXITSTATUS(status);
			}
			tok_free(argums);
		}
	}

	free(buf);
	return (status);
}

