#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
        va_list args;
        int i = 0, j = 0, count = 0;
        char *str;

        va_start(args, format);
        while (format && format[i])
        {
                if (format[i] == '%')
                {
                        i++;
                        if (format[i] == '\0')
                                return (-1);
                        while (format[i] == ' ')
                                i++;
                        if (format[i] == '%')
                                count += _putchar('%');
                        else if (format[i] == 'c')
                                count += print_char(args);
                        else if (format[i] == 's')
                        {
                                str = va_arg(args, char *);
                                if (str == NULL)
                                        count += print_str("(null)");
                                else
                                        count += print_str(str);
                        }
                        else if (format[i] == 'd' || format[i] == 'i')
                                count += print_int(args);
                        else if (format[i] == 'u')
                                count += print_unsigned_int(args);
                        else if (format[i] == 'o')
                                count += print_octal(args);
                        else if (format[i] == 'x' || format[i] == 'X')
                                count += print_hex(args, (format[i] == 'x'));
                        else if (format[i] == 'p')
                                count += print_pointer(args);
                        else if (format[i] == 'S')
                                count += print_custom(args, 'S');
                        else if (format[i] == 'r')
                                count += print_rev(args);
                        else if (format[i] == 'R')
                                count += print_rot13(args);
                        else if (format[i] == 'b')
                                count += print_uint_to_binary(va_arg(args, unsigned int));
                        else
                        {
                                count += _putchar('%');
                                count += _putchar(format[i]);
                        }
                }
                else
                        count += _putchar(format[i]);
                i++;
        }
        va_end(args);
        return (count);
}

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1, on error, -1 is returned
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}



/**
 * print_uint_to_octal - Prints an unsigned integer in octal format.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
unsigned int print_uint_to_octal(unsigned int n)
{
    unsigned int count = 0, i;
    char octal[100];

    if (n == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        for (i = 0; n > 0; i++)
        {
            octal[i] = (n % 8) + '0';
            n /= 8;
        }

        for (i--; i >= 0; i--)
        {
            _putchar(octal[i]);
            count++;
        }
    }

    return (count);
}

/**
 * print_uint_to_binary - prints an unsigned integer in binary notation
 * @n: the unsigned integer to be printed
 *
 * Return: the number of digits printed
 */
unsigned int print_uint_to_binary(unsigned int n)
{
    unsigned int count = 0;
    unsigned int binary[32];
    unsigned int i;

    if (n == 0)
    {
        count += _putchar('0');
        return (count);
    }

    for (i = 0; n > 0; i++)
    {
        binary[i] = n % 2;
        n /= 2;
    }

    for (i--; i < 32; i--)
    {
        count += _putchar(binary[i] + '0');
    }

    return (count);
}
/**
 * print_uint_recursive - Recursively prints an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
unsigned int print_uint_recursive(unsigned int n)
{
	unsigned int len = 0;

	if (n / 10)
		len += print_uint_recursive(n / 10);

	_putchar((n % 10) + '0');
	len++;

	return (len);
}

/**
 * print_uint - Prints an unsigned integer
 * @args: The va_list containing the unsigned int to print
 *
 * Return: The number of characters printed
 */
unsigned int print_uint(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);

    return (n == 0 ? _putchar('0') : print_uint_recursive(n));
}


/**
 * print_char - prints a character
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
        char c = va_arg(args, int);
        _putchar(c);
        return (1);
}

/**
 * print_str - prints a string
 * @args: argument list
 *
 * Return: number of characters printed
 */
int print_str(va_list args)
{
        int i = 0, count = 0;
        char *str = va_arg(args, char *);

        while (str && str[i])
        {
                count += _putchar(str[i]);
                i++;
        }
        return (count);
}

/**
 * print_int - Prints an integer
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    int num_len = count_digits(n);
    int num = n, res = 0, i = 0;

    if (n < 0)
    {
        num = -n;
        res += _putchar('-');
        i++;
    }

    res += print_number(num, num_len);
    return (res);
}


/**
 * print_unsigned_int - Prints an unsigned integer
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_unsigned_int(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int num_len = count_digits_unsigned(n);
    int res = 0;

    res += print_number_unsigned(n, num_len);
    return (res);
}

/**
 * print_octal - Prints an unsigned integer in octal format to stdout.
 * @args: A va_list containing an unsigned integer.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_uint_to_octal(n));
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format to stdout.
 * @args: A va_list containing an unsigned integer.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list args, int lowercase)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_uint_to_hex(n, lowercase));
}

/**
 * print_pointer - Prints the memory address of a pointer argument
 * @args: A va_list containing the pointer argument to print
 *
 * Return: The number of characters printed
 */
int print_pointer(va_list args)
{
    void *p = va_arg(args, void *);

    _putchar('0');
    _putchar('x');
    return (print_uint_to_hex((unsigned long int)p, 0) + 2);
}

/**
 * print_rot13 - Prints a string in rot13 encoding.
 *
 * @args: A va_list pointing to the string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_rot13(va_list args)
{
    int i, j, count = 0;
    char *str, *rot13 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char *rot13_encrypted = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(args, char *);

    if (str == NULL)
        str = "(null)";

    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = 0; rot13[j] != '\0'; j++)
        {
            if (str[i] == rot13[j])
            {
                count += _putchar(rot13_encrypted[j]);
                break;
            }
        }
        if (!rot13[j] && (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122))
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += _putchar((str[i] / 16) + 48);
            if (str[i] % 16 < 10)
                count += _putchar(str[i] % 16 + 48);
            else
                count += _putchar(str[i] % 16 + 55);
        }
        else if (!rot13[j])
        {
            count += _putchar(str[i]);
        }
    }

    return (count);
}

/**
 * print_rev - prints a string in reverse
 * @args: arguments list containing the string to print
 *
 * Return: number of characters printed
 */
int print_rev(va_list args)
{
        char *s = va_arg(args, char *);
        int len = 0;

        if (s == NULL)
                s = "(null)";

        while (s[len] != '\0')
                len++;

        for (len--; len >= 0; len--)
                _putchar(s[len]);

        return strlen(s);
}

/**
 * print_custom - handles custom conversion specifier
 * @args: va_list containing the arguments
 * @c: the custom conversion specifier character
 *
 * Return: the number of characters printed
 */
int print_custom(va_list args, char c)
{
    int count = 0;
    char *str;

    if (c == 'r')
    {
        str = va_arg(args, char *);
        if (str == NULL)
            str = "(null)";
        count = print_rev_string(str);
    }
    else if (c == 'R')
    {
        str = va_arg(args, char *);
        if (str == NULL)
            str = "(null)";
        count = print_rot13_string(str);
    }
    else if (c == 'S')
    {
        str = va_arg(args, char *);
        if (str == NULL)
            str = "(null)";
        count = print_special_string(str);
    }
    else
    {
        _putchar('%');
        _putchar(c);
        count = 2;
    }

    return (count);
}




