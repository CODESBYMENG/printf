#include "main.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    int len1, len2;
    char *str = "Hello, world!";
    
    /*Test the %c specifier.*/
    _printf("%c\n", 'H');
    printf("%c\n", 'H');

    /*Test the %s specifier*/
    len1 = _printf("%s\n", str);
    len2 = printf("%s\n", str);
    printf("len1: %d, len2: %d\n", len1, len2);
    
    /*Test the %% specifier*/
    _printf("%%\n");
    printf("%%\n");

    /*Test invalid input*/
    _printf("This is an %d\n", 123);
    
    return (0);
}
