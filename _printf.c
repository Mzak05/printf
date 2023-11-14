#include "main.h"
/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list args;
va_start(args, format);
while (*format)
{
if (*format != '%')
printed_chars += write(1, format, 1); 
else
{
format++;
if (*format == 'c')
{
char c = va_arg(args, int);
printed_chars += write(1, &c, 1);
}
else if (*format == 's')
{
char *str = va_arg(args, char*);
while (*str)
{
printed_chars += write(1, str, 1);
str++;
}
}
else if (*format == '%')
{
printed_chars += write(1, format, 1);
}
else
{
write(1, "%", 1);
write(1, format, 1);
printed_chars += 2;
}
}
format++;
}
va_end(args);
return (printed_chars);
}
