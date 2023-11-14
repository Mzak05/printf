#include "main.h"
/**
 * _puso - info
 * @c: The character to print
 * Return: o
 */
int _puso(char *c)
{
int i;
for (i = 0; c[i] != '\0'; i++)
{
_putca(c[i]);
}
return (i - 1);
}
