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

/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
va_list list;
int c, i, j;
c = 0;
if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);
va_start(list, format);
for (i = 0; format[i]; i++)
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
break;

if (format[i] == '%')
c += write(1, &format[i], 1);

else if (format[i] == 'c')
{
char ch = va_arg(list, int);
c += write(1, &ch, 1);
}
else if (format[i] == 's')
{
const char *t = va_arg(list, const char *);
if (t)
for (j = 0; t[j]; j++)
c += write(1, &t[j], 1);
}
else if (format[i] == 'd' || format[i] == 'i')
{
	int num = va_arg(list, int);
	char buffer[20];
	int L = _inttoASC(num, buffer);

	c += write(1, buffer, L);
}
else
{
c += write(1, "%", 1);
c += write(1, &format[i], 1);
}
}
else
c += write(1, &format[i], 1);
}
va_end(list);
return (c);
}

