#include "main.h"

/**
 * parse_format - parses the format string and handles format specifiers
 * @format: character string
 * @args: va_list containing arguments to be printed
 *
 * Return: number of characters printed
 */
int parse_format(const char *format, va_list args)
{
	char ch;
	int i = 0, printed_chars = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ch = format[i];

			if (ch == 'c')
				printed_chars += print_char(args);

			else if (ch == 's')
				printed_chars += print_string(args);

			else if (ch == 'd' || ch == 'i')
				printed_chars += print_int(args);

			else if (ch == 'b')
				printed_chars += print_binary(args);

			else if (ch == 'u')
				printed_chars += print_unsigned(args);

			else if (ch == 'o')
				printed_chars += print_octal(args);

			else if (ch == 'x' || ch == 'X')
				printed_chars += print_hex(args, ch);

			else if (ch == 'p')
				printed_chars += print_pointer(args);

			else if (ch == '%')
				printed_chars += print_percent();

			else if (ch == 'r')
				printed_chars += print_rev_string(args);

			else if (ch == 'R')
				printed_chars += print_rot13(args);

			else
			{
				printed_chars += _putchar('%');
				if (format[i] != '\0')
					printed_chars += _putchar(format[i]);
				else
					return (-1);
			}
		}
		else
			printed_chars += _putchar(format[i]);

		i++;
	}

	return (printed_chars);
}
