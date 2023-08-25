#ifndef _SUBSTRING_H_
#define _SUBSTRING_H_

#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* _SUBSTRING_H_ */
