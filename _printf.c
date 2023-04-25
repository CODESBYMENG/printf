#include <stdio.h>
#include <stdarg.h>
/**
 * @brief _printf - function to print based on the format specifier
 * @param format : takes a format specifier
 * @param ...
 * @return int
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
