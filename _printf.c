#include "main.h"
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
if (!format)
return (-1);

va_start(list, format);
for (i = 0; format[i]; i++)
{
if (format[i] == '%')
{
i++;
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
