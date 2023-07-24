#include "main.h"

/**
 * comnd_exec - attempts to execute a command specified by args[0]
 * @args: pointer to an array of strings
 * @env: pointer to an array of strings
 * Return: The function does not return any value
 */
void comnd_exec(char **args, char **env)
{
	char *comnd = comand_get(args[0]);

	if (comnd)
	{
		if (execve(comnd, args, env) == -1)
		{
			perror("error");
			free(comnd);
			exit(1);
		}
	}
	else
	{
		printf("not found\n");
		exit(1);
	}
}
