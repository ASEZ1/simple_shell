#include "main.h"

/**
 * str_split - splits a string into an array of tokens
 * @buf: pointer to the string to be split
 * @del: pointer to the delimiter string used for splitting
 * Return: returns a pointer to a dynamically allocated array of pointers
 */
char **str_split(char *buf, const char *del)
{
	char **tok = NULL;
	int n_tok = 0;
	char *strike = strtok(buf, del);

	while (strike)
	{
		tok = _realc(tok, n_tok * sizeof(char *), (n_tok + 1) * sizeof(char *));
		if (!tok)
		{
			perror("error");
			exit(1);
		}

		tok[n_tok] = (char *)malloc(strlen(strike) + 1);
		if (!tok[n_tok])
		{
			perror("error");
			exit(1);
		}

		strcpy(tok[n_tok], strike);

		n_tok++;
		strike = strtok(NULL, del);
	}

	tok = _realc(tok, n_tok * sizeof(char *), (n_tok + 1) * sizeof(char *));
	if (!tok)
	{
		perror("error");
		exit(1);
	}
	tok[n_tok] = NULL;
	return (tok);
}
