#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

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
    char int_str[12];  // Enough space to hold any 32-bit integer

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
                    count += write(1, &ch, 1);
                    break;
                case 's':
                    str_arg = va_arg(args, char *);
                    if (str_arg == NULL)
                        str_arg = "(null)";
                    while (str_arg[j])
                    {
                        count += write(1, &str_arg[j], 1);
                        j++;
                    }
                    j = 0;
                    break;
                case 'd':
                case 'i':
                    int_arg = va_arg(args, int);
                    sprintf(int_str, "%d", int_arg);
                    while (int_str[j])
                    {
                        count += write(1, &int_str[j], 1);
                        j++;
                    }
                    j = 0;
                    break;
                case '%':
                    count += write(1, &format[i], 1);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, &format[i], 1);
                    break;
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }

        i++;
    }

    va_end(args);

    return count;
}
