#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
va_list list;
int c, j;
c = 0;
va_start(list, format);
while (*format)
{
if (*format != '%')
{
c += write(1, format, 1);
}
else
{
format++;
if (*format == '\0')
break;

if (*format == 'c' || *format == '%')
{
char t = (*format == 'c') ? va_arg(list, int) : '%';
c += write(1, &t, 1);
}
else if (*format == 's')
{
char *info = va_arg(list, char *);
j = 0;
while (info[j] != '\0')
{
c += write(1, &info[j], 1);
j++;
}
}
}
format++;
}
va_end(list);
return (c);
}
