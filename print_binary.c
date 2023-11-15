#include "main.h"

/**
 * print_binary - custom conversion
 * @num: int
 * @buffer: char
*/

int print_binary(unsigned int num, char buffer[])
{
	if (buffer == NULL)
	{
		return (-1);
	}
	int c = 0;
	int i = 0;

	if (num == 0)
	{
		buffer[i++] = '0';
		c++;
	}
	else
	{
		for (unsigned int m = 1u <<(sizeof(unsigned int) * 8 - 1); m > 0; m >>= 1)
		{
			if (num & m)
			{
				buffer[i++] = '1';
				c++;
			}
			else
			{
				if (c > 0)
				{
					buffer[++] = '0';
				}
			}
		}
	}
	buffer[i] = '\0';
	return (c);
}
