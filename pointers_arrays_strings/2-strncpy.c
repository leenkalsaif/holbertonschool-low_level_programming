#include "main.h"

/**
 * _strncpy - copies at most n bytes of a string
 * @dest: the destination buffer
 * @src: the source string
 * @n: number of bytes to write into dest
 *
 * Return: a pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
