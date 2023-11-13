#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list list;
int c, i, j;
va_start(list, format);
c = 0;
if (!format)
return (-1);

for (i = 0; format[i]; i++)
{
if (format[i] != '%')
{
c += write(1, &format[i], 1);
}
else
{
i++;
if (format[i] == '%')
{
c += write(1, "%", 1);
}
if (format[i] == 'c')
{
char var = va_arg(list, int);
c += write(1, &var, 1);
}
if (format[i] == 's')
{
const char *t = va_arg(list, const char *);
if (t)
{
for (j = 0; t[j]; j++)
{
c += write(1, &t[j], 1);
}
}
}
}
}
va_end(list);
return (c);
}
