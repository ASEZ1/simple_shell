#include "main.h"

/**
 * tok_free - Frees the memory allocated for the tokens array.
 * @tokens: Pointer to the tokens array to be freed.
 * Return: None.
 */
void tok_free(char **tokens)
{
	char **token_ptr = tokens;

	while (*token_ptr)
	{
		free(*token_ptr);
		token_ptr++;
	}
	free(tokens);
}
