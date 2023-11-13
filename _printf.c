#include "main.h"
/**
* _printf - Printf function
* @format: Format string.
* Return: Number of printed characters.
*/
int _printf(const char *format, ...)
{
va_list list;
int i, j, printed_chars;
printed_chars = 0;
if (format == NULL)
return (-1);

va_start(list, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] != '%')
{
printed_chars += write(1, &format[i], 1);
}
else
{
i++;
if (format[i] == '%' || format[i] == 'c')
{
char ch = (format[i] == '%') ? '%' : va_arg(list, int);
printed_chars += write(1, &ch, 1);
}
else if (format[i] == 's')
{
const char *str = va_arg(list, const char *);
if (str)
{
for (j = 0; str[j] != '\0'; j++)
{
printed_chars += write(1, &str[j], 1);
}
}
}
}
}
va_end(list);
return (printed_chars);
}
