#include "main.h"

/**
* _printf1 - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf1(const char *format, ...)
{
va_list list;
int c, i;
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

