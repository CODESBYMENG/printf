#include "main.h"

/**
 * parse_format - parses format string and prints arguments
 * @format: format string
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int parse_format(const char *format, va_list args)
{
	char *str_arg;
	int i, j, len = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] == ' ')
				i++;
			if (!format[i])
				return (-1);
			if (format[i] == '%')
				len += _putchar('%');
			else if (format[i] == 'c')
				len += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				str_arg = va_arg(args, char *);
				if (!str_arg)
					str_arg = "(null)";
				len += _puts(str_arg);
			}
			else if (format[i] == 'd' || format[i] == 'i')
				len += print_number(args, 10, 1);
			else if (format[i] == 'b')
				len += print_number(args, 2, 0);
			else if (format[i] == 'u')
				len += print_number(args, 10, 0);
			else if (format[i] == 'o')
				len += print_number(args, 8, 0);
			else if (format[i] == 'x' || format[i] == 'X')
				len += print_hex(args, format[i]);
			else if (format[i] == 'p')
				len += print_address(args);
			else
			{
				len += _putchar('%');
				if (format[i] != '\0')
					len += _putchar(format[i]);
				else
					return (-1);
			}
		}
		else
			len += _putchar(format[i]);
	}
	return (len);
}


/**
 * print_hex - prints a number in hexadecimal format
 * @args: va_list containing the number to print
 * @format: format specifier ('x' or 'X')
 *
 * Return: number of characters printed
 */
int print_hex(va_list args, char format)
{
    unsigned int num = va_arg(args, unsigned int);
    char hex[100];
    int i = 0, len = 0;

    if (format == 'x')
    {
        while (num)
        {
            int temp = 0;
            temp = num % 16;
            if (temp < 10)
                hex[i] = temp + 48;
            else
                hex[i] = temp + 87;
            num = num / 16;
            i++;
        }
        if (i == 0)
            hex[i++] = '0';

        while (i--)
            len += _putchar(hex[i]);
    }
    else if (format == 'X')
    {
        while (num)
        {
            int temp = 0;
            temp = num % 16;
            if (temp < 10)
                hex[i] = temp + 48;
            else
                hex[i] = temp + 55;
            num = num / 16;
            i++;
        }
        if (i == 0)
            hex[i++] = '0';

        while (i--)
            len += _putchar(hex[i]);
    }

    return (len);
}