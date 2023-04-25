#include <unistd.h>
#include <stdlib.h>
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
    char *str;

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
                    char c = (char) va_arg(args, int);
                    write(1, &c, 1);
                    printed_chars++;
                    break;
                }
                case 's':
                {
                    str = va_arg(args, char *);
                    if (str == NULL)
                    {
                        write(1, "(null)", 6);
                        printed_chars += 6;
                    }
                    else
                    {
                        while (*str != '\0')
                        {
                            write(1, str, 1);
                            printed_chars++;
                            str++;
                        }
                    }
                    break;
                }
                case '%':
                {
                    write(1, "%", 1);
                    printed_chars++;
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    int num_copy = num;
                    int num_len = 0;
                    if (num == 0)
                    {
                        write(1, "0", 1);
                        printed_chars++;
                    }
                    if (num < 0)
                    {
                        write(1, "-", 1);
                        printed_chars++;
                        num = -num;
                        num_copy = -num_copy;
                    }
                    while (num > 0)
                    {
                        num /= 10;
                        num_len++;
                    }
                    while (num_len > 0)
                    {
                        num_len--;
                        int div = 1;
                        int i = num_len;
                        while (i > 0)
                        {
                            div *= 10;
                            i--;
                        }
                        int digit = num_copy / div;
                        char c = digit + '0';
                        write(1, &c, 1);
                        printed_chars++;
                        num_copy %= div;
                    }
                    break;
                }
                default:
                {
                    write(1, "%", 1);
                    printed_chars++;
                    format--;
                    break;
                }
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }
        format++;
    }

    va_end(args);
    return printed_chars;
}

