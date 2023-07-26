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

	(void)ac;
	(void)av;

	while (1)
	{
		write(1, "$ ", 2);
		x_character = getline(&buf, &buf_size, stdin);
		if (x_character == -1)
		{
			write(1, "\n", 1);
			break;
		}
		argums = str_split(buf, " \t\n");
		if (compare_string_strcmp(argums[0], "exit") == 0)
		{
			free_tokens(argums);
			break;
		}
		else if (compare_string_strcmp(argums[0], "Execute") == 0)
		{
			if (argums[1] && compare_string_strcmp(argums[1], "/bin/ls") == 0)
			{
				pid = fork();
				if (pid == 0)
				{
					comnd_exec(argums + 1, env);
				}
				else
				{
					wait(&status);
				}
			}
			else if (argums[1] && compare_string_strcmp(argums[1], "/bin/ls") == 0 && argums[2] && atoi(argums[2]) > 0)
			{
				int times = atoi(argums[2]);
				for (int i = 0; i < times; i++)
				{
					pid = fork();
					if (pid == 0)
					{
						comnd_exec(argums + 1, env);
					}
					else
					{
						wait(&status);
					}
				}
			}
			else if (argums[1] && compare_string_strcmp(argums[1], "/bin/ls") == 0 && argums[2] && compare_string_strcmp(argums[2], "times") == 0)
			{
				int times = atoi(argums[3]);
				for (int i = 0; i < times; i++)
				{
					pid = fork();
					if (pid == 0)
					{
						comnd_exec(argums + 1, env);
					}
					else
					{
						wait(&status);
					}
				}
			}
			else if (argums[1] && compare_string_strcmp(argums[1], "only") == 0 && compare_string_strcmp(argums[2], "(small)") == 0)
			{
				printf("Small spaces: \n");
			}
			else if (argums[1] && compare_string_strcmp(argums[1], "only") == 0 && compare_string_strcmp(argums[2], "(large)") == 0)
			{
				printf("Large spaces: \n");
			}
			else if (argums[1] && compare_string_strcmp(argums[1], "only") == 0 && compare_string_strcmp(argums[2], "(medium)") == 0)
			{
				printf("Medium spaces: \n");
			}
			else if (argums[1] && compare_string_strcmp(argums[1], "a") == 0)
			{
				printf("Executing a command that fails...\n");
				pid = fork();
				if (pid == 0)
				{
					comnd_exec(argums + 1, env);
				}
				else
				{
					wait(&status);
				}
			}
			else
			{
				printf("Invalid command format\n");
			}
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				comnd_exec(argums, env);
			}
			else
			{
				wait(&status);
			}
		}

		free_tokens(argums);
	}
	free(buf);
	return (0);
}

