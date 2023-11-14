#include <unistd.h>
/**
* pop - writes the character c to stdout
* @c: The character to print
* Return: On success
*/
int pop(char *c)
{
int i;
if (c == NULL)
{
write(1, "(null)", 1);
return (1);
}
for (i = 0; c[i] != '\0'; i++)
{
write(1, &c[i], 1);
}
return (i - 1);
}
