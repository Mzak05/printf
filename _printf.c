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
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
write(1, &format[i], 1);
printed_chars++;
}
else
{
if (format[i + 1] == '%' || format[i + 1] == 'c')
{
char ch = '%';
printed_chars += write(1, &ch, 1);
}
else if (format[i + 1] == 's')
{
const char *str = va_arg(list, const char *);
if (str)
{
j = 0;
while (str[j] != '\0')
{
write(1, &str[j], 1);
j++;
printed_chars++;
}
}
}
i++;
}
}
va_end(list);
return (printed_chars);
}
