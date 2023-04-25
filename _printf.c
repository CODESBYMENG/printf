#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf: Produces output according to a format
 * 
 * @args: format a character string composed
 * of zero or more directives
 * @format: additional arguments to be printed
 * according to the format string
 * Return: the number of characters printed (excluding
 * the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char ch;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    count += printf("%d", va_arg(args, int));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
