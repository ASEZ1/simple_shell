#include "main.h"

/**
 * _memcpy - Copies 'n' bytes from the memory area to another
 * @adress: Pointer to the destination memory area.
 * @srcpy: Pointer to the source memory area.
 * @n: Number of bytes to be copied.
 *
 * Return: A pointer to the destination memory area.
 */
void *_memcpy(void *adress, const void *srcpy, size_t n)
{
	char *a = adress;
	const char *s = srcpy;

	if (adress == NULL || srcpy == NULL)
	{
		return (NULL);
	}
	while (n--)
	{
		*a++ = *s++;
	}
	return (adress);
}

/**
 * _realc - Resizes the memory block
 * @ptr: Pointer to the memory block to be resized
 * @old_size: Old size of the memory block
 * @up_size: New size of the memory block
 *
 * Return: Pointer to the resized memory block
 */
void *_realc(void *ptr, size_t old_size, size_t up_size)
{
	void *up_ptr;

	if (up_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(up_size));
	}

	up_ptr = malloc(up_size);
	if (up_ptr)
	{
		size_t copy_size = (up_size < old_size) ? up_size : old_size;

		memcpy(up_ptr, ptr, copy_size);

		free(ptr);
	}
	return (up_ptr);
}
