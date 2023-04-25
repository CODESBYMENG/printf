#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @format: a character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to
 *         end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    while (*s != '\0')
                    {
                        putchar(*s);
                        printed_chars++;
                        s++;
                    }
                    break;
                }
                case '%':
                {
                    putchar('%');
                    printed_chars++;
                    break;
                }
                case 'd':
                case 'i':
                {
                    int d = va_arg(args, int);
                    printf("%d", d);
                    printed_chars += snprintf(NULL, 0, "%d", d);
                    break;
                }
                default:
                {
                    putchar(*format);
                    printed_chars++;
                    break;
                }
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}
