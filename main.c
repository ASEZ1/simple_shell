#include "main.h"

int main(int ac, char **av, char **env)
{
	size_t buf_size = 0;
	char *buf = NULL;
	char **argums = NULL;
	pid_t pid;
	int status;
	int inter = 1;
	int count_commands = 0;

	(void)ac;
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
		ssize_t x_character = getline(&buf, &buf_size, stdin);
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


		for (int i = 0; argums[i] != NULL; i++)
		{
			if (compare_string_strcmp(argums[i], argums[0]) == 0)
				count_commands++;
		}


		if (count_commands == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				pid = fork();
				if (pid == 0)
				{

					char *cmd = malloc(strlen(buf) + 3);
					sprintf(cmd, " %s ", buf);
					argums[0] = cmd;

					comnd_exec(argums, env);
					exit(EXIT_SUCCESS);
				}
				else
				{
					wait(&status);
				}
			}
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				comnd_exec(argums, env);
				exit(EXIT_SUCCESS);
			}
			else
			{
				wait(&status);
			}
		}

		tok_free(argums);
	}

	free(buf);
	return 0;
}

