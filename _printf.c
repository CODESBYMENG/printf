#include "main.h"

/**
 * _printf - produces output according to a format.
 *
 * @format: character string
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list arg_list;

	if (!format)
		return (-1);

	va_start(arg_list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			while (*format == ' ')
				format++;
			if (*format == '%')
				printed_chars += write(1, format++, 1);
			else if (*format == 'c')
				printed_chars += print_char(arg_list);
			else if (*format == 's')
				printed_chars += print_string(arg_list);
			else if (*format == 'd' || *format == 'i')
				printed_chars += print_int(arg_list);
			else if (*format == 'u')
				printed_chars += print_uint(arg_list);
			else if (*format == 'o')
				printed_chars += print_uint_to_octal(arg_list);
			else if (*format == 'x' || *format == 'X')
				printed_chars += print_uint_to_hex(arg_list, *format);
			else if (*format == 'b')
				printed_chars += print_uint_to_binary(arg_list);
			else if (*format == 'S')
				printed_chars += print_custom_string(arg_list);
			else if (*format == 'p')
				printed_chars += print_pointer(arg_list);
			else if (*format == 'r')
				printed_chars += print_rev(arg_list);
			else if (*format == 'R')
				printed_chars += print_rot13(arg_list);
			else
			{
				printed_chars += write(1, "%", 1);
				printed_chars += write(1, format, 1);
			}
		}
		else
			printed_chars += write(1, format, 1);
		format++;
	}

	va_end(arg_list);
	return (printed_chars);
}
