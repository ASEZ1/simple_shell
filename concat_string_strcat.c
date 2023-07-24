#include "main.h"

/**
 * concat_string_strcat - appends the source string src to string dest.
 * @address: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: returns a pointer of the modified string dest
 */
char *concat_string_strcat(char *address, const char *src)
{
	char *p = address + Length_string_strlen(address);

	while ((*p++ = *src++))
	{
	}
	return (address);
}
