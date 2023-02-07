/**
* is_palindrome - checks if an integer is palindrome
*
* @n: input integer
* Return: 1 if n is palindrome, 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	unsigned long n2 = n;
	unsigned long n_len = 0, l_digit = 1, r_digit = 10;

	for (; n2; n_len++, l_digit *= 10)
		n2 /= 10;
	l_digit /= 10;
	for (; l_digit >= r_digit; l_digit /= 10, r_digit *= 10)
	{
		if (((n / l_digit) % 10) != ((n % r_digit) / (r_digit / 10)))
			return (0);
	}
	return (1);
}
