#include "main.h"

/**
 * compare_string_strcmp - Compares two strings s1 and s2
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return:
 *   -1 if s1 is less than s2
 *    0 if s1 is equal to s2
 *    1 if s1 is greater than s2
 */
int compare_string_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return ((int)(unsigned char)(*s1) - (int)(unsigned char)(*s2));
}
