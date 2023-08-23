#include <stdlib.h>
#include <stddef.h>

/*
 * strcat - Concatenates two strings together src to dest
 * str_concat - Concatenates two strings together. also allocates
 *               memory for old string new string size.
 *               may probably free str1 when done.
 * strchr - Checks for char in a string and returns pointer
 * 
 * strcmp - compares if two strings match returns 0 if true
 * strcpy - Copies all bytes of src to dest (string)
 */

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: less than 0 if s1 less than s2, 0 if equal,
 * more than 0 if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcpy - Returns number of elements in string
 * @dest: Destination
 * @src: Source
 *
 * Return: dest (for Success)
 */

char *_strcpy(char *dest, char *src)
{
	char *start_d = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (start_d);

	/**/
}
