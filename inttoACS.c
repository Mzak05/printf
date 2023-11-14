#include "main.h"

/**
 * _inttoASC - converts an integer into a string
 * @AC: buffer where result is stored
 * @number: an integer that we should convert
 * Return: the length of the AC string
*/
int _inttoASC(int number, char *AC)
{
	int i = 0, first, last;

	if (number == 0)
	{
		AC[i] = '0';
		AC[++i] = '\0';
		return (1);
	}
	if (number < 0)
	{
		AC[i++] = '-';
		number = (-number);
	}
	while (number != 0)
	{
		int rest = number % 10;

		AC[i++] = rest + '0';
		number = number / 10;
	}
	AC[i] = '\0';
	first = 0;
	last = (i - 1);
	while (first < last)
	{
		char tomp = AC[first];

		AC[first] = AC[last];
		AC[last] = tomp;
		first++;
		last--;
	}
	return (i);
}

