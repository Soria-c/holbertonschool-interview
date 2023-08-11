#include "holberton.h"

/**
 * wildcmp - Compares two strings and returns 1 if the strings can be
 * considered identical, otherwise return 0.
 * @s1: String
 * @s2: String with wildcard to compare with s1
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 != '*')
		return (0);
	return (*(s2 + 1) == '*' ? wildcmp(s1, s2 + 1) :
		wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
}
