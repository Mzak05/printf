#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
va_list args;
int count;
count = 0;
va_start(args, format);
while (*format != '\0')
{
if (*format != '%')
count += write(1, format, 1);
else
{
switch (*++format)
{
char c;
case 'c':
c = va_arg(args, int);
count += write(1, &c, 1);
break;
case 's':
{
const char *str = va_arg(args, const char *);
while (*str != '\0')
{
count += write(1, str++, 1);
}
break;
}
case '%':
count += write(1, "%", 1);
break;
default:
return (-1);
break;
}
}
format++;
}
va_end(args);
return (count);
}
