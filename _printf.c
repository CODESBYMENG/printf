include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string composed of zero or more directives
 * that produces output when the directive is encountered.
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i = 0, j = 0;
    char *str_arg, ch;
    int int_arg;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    ch = (char)va_arg(args, int);
                    count += printf("%c", ch);
                    break;
                case 's':
                    str_arg = va_arg(args, char *);
                    if (str_arg == NULL)
                        str_arg = "(null)";
                    count += printf("%s", str_arg);
                    break;
                case '%':
                    count += printf("%%");
                    break;
                case 'd':
                case 'i':
                    int_arg = va_arg(args, int);
                    count += printf("%d", int_arg);
                    break;
                default:
                    count += printf("%%");
                    count += printf("%c", format[i]);
                    break;
            }
        }
        else
        {
            count += printf("%c", format[i]);
        }

        i++;
    }

    va_end(args);

    return count;
}
