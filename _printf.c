#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int pop(char *c);
int _printf(const char *format, ...)
{
int c;
char t;
char *st;
va_list list;
c = 0;
if (format == NULL)
	return (-1);
va_start(list, format);
while (*format)
{
if (*format != '%')
	c += write(1, format, 1);
else
{
format++;
if (*format == '\0')
break;
switch (*format)
{
case '%':
	c += write(1, "%", 1);
	break;
case 'c':
t = va_arg(list, int);
c += write(1, &t, 1);
break;
case 's':
	st = va_arg(list, char *);
	c += pop(st);
break;
default:
return (-1);
break;
}
}
format++;
}
va_end(list);
return (c);
}
