#include "palindrome.h"
/**
 * is_palindrome - checks if a number is a palindrome
 * @n: the number to check
 * Return: 1 if n is palindrome 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed, remainder, original;
	reversed = 0;
	original = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}
	if (original == reversed)
		return (1);
	else
		return (0);
}
