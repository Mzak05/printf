#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
va_list list;
int c, i;
c = 0;
if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);

va_start(list, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
_putca(format[i]);
c++;
}
else if (format[i + 1] == '%')
{
_putca('%');
c++;
i++;
}
else if (format[i + 1] == 'c')
{
_putca(va_arg(list, int));
c++;
i++;
}
else if (format[i + 1] == 's')
{
c += _puso(va_arg(list, char *));
c = c - 1;
i++;
}
}
va_end(list);
return (c);
}
