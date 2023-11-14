#include "main.h"
#include <stdio.h>

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    printf("Length:[%d]\n", len);

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    len = _printf("Percent:[%%]\n");
    printf("Len:[%d]\n", len);

    return (0);
}

