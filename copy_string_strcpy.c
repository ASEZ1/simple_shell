#include "main.h"

/**
 * copy_string_strcpy - Copy a string from the source to the buffer
 * @address: destination buffer pointer
 * @src: source string pointer
 *
 * Return: Pointer to the beginning of the destination buffer
 */
char *copy_string_strcpy(char *address, const char *src)
{
	char *p = address;

	while ((*p++ = *src++))
	{
	}
	return (address);
}
