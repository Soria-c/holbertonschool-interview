#include "substring.h"

/**
 * find_substring -  finds all the possible substrings containing a list of
 * words, within a given string
 * @s: string to scan
 * @words:  array of words all substrings must be a concatenation=
 * arrangement of
 * @nb_words: number of elements in the array words
 * @n: address at which to store the number of elements in the returned array
 *
 * Return:  an allocated array, storing each index in s, at which a
 * substring was found. If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{

	int i, j, k, current_index, count, string_len, len_of_words, check_strings;
	int *index_array, *matched;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	string_len = strlen(s);
	len_of_words = strlen(words[0]);
	index_array = malloc(string_len * sizeof(int));
	if (!index_array)
		return (NULL);
	matched = malloc(nb_words * sizeof(int));
	if (!matched)
		return (NULL);

	for (i = count = 0; i <= string_len - nb_words * len_of_words; i++)
	{
		memset(matched, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				current_index = i + j * len_of_words;
				check_strings = strncmp(s + current_index, *(words + k), len_of_words);
				if (!*(matched + k) && !check_strings)
				{
					*(matched + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(index_array + count) = i, count += 1;
	}
	free(matched);
	*n = count;
	return (index_array);
}
