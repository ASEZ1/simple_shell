#include "main.h"

/**
 * str_split - splits a string into an array of tokens
 * @buf: pointer to the string to be split
 * @del: pointer to the delimiter string used for splitting
 * Return: returns a pointer to a dynamically allocated array of pointers
 */
char **str_split(char *buf, const char *del)
{
	char **tokens = NULL;
	int n_tokens = 0;
	char *strike = strtok(buf, del);

	while (strike)
	{
		tokens = _realc(tokens, n_tokens * sizeof(char *), (n_tokens + 1) * sizeof(char *));
		if (!tokens)
		{
			perror("error");
			exit(1);
		}

		tokens[n_tokens] = (char *)malloc(strlen(strike) + 1);
		if (!tokens[n_tokens])
		{
			perror("error");
			exit(1);
		}

		strcpy(tokens[n_tokens], strike);

		n_tokens++;
		strike = strtok(NULL, del);
	}

	tokens = _realc(tokens, n_tokens * sizeof(char *), (n_tokens + 1) * sizeof(char *));
	if (!tokens)
	{
		perror("error");
		exit(1);
	}
	tokens[n_tokens] = NULL;
	return (tokens);
}
