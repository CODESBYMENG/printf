#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 * @...: variable arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0, len;
    char *str;
    void *arg = (void *)&format + sizeof(format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += write(1, arg, 1);
                    arg += sizeof(int);
                    break;
                case 's':
                    str = *(char **)arg;
                    len = 0;
                    while (str[len] != '\0')
                        len++;
                    count += write(1, str, len);
                    arg += sizeof(char *);
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, format, 1);
                    break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }
        format++;
    }

    return count;
}

