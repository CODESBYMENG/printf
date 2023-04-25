/**
 * @brief Produces output according to a format
 * 
 * @param format a character string composed of zero or more directives
 * @param ... additional arguments to be printed according to the format string
 * @return the number of characters printed (excluding the null byte used to end output to strings)
 */
#include <stdio.h>
#include <stdarg.h>

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


/**
 * _printf - Custom implementation of printf function
 *
 * @format: A string containing zero or more directives to produce the output
 * @...: A variable number of arguments to be printed
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char ch, *str;
    int num;

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
                    write(1, &ch, 1);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    count += write(1, str, strlen(str));
                    break;
                case 'd':
                case 'i':
                    num = va_arg(args, int);
                    char *num_str = malloc(12 * sizeof(char)); // max int value takes 10 digits plus one sign and one null terminator
                    sprintf(num_str, "%d", num);
                    count += write(1, num_str, strlen(num_str));
                    free(num_str);
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    write(1, "%", 1);
                    write(1, &(*format), 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            write(1, &(*format), 1);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}