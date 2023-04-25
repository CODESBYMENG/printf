#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: The number of bytes written.
 */
int _putchar(char c)
{
  return write(1, &c, 1);
}

/**
 * _putstr - Writes a string to stdout.
 * @str: The string to write.
 *
 * Return: The number of bytes written.
 */
int _putstr(char *str)
{
  int len = 0;

  while (*str)
  {
    _putchar(*str++);
    len++;
  }

  return len;
}

/**
 * _putint - Writes an integer to stdout.
 * @n: The integer to write.
 *
 * Return: The number of digits written.
 */
int _putint(int n)
{
  if (n == 0)
  {
    return _putchar('0');
  }

  if (n < 0)
  {
    _putchar('-');
    n = -n;
  }

  int digits = 0;
  int temp = n;

  while (temp)
  {
    digits++;
    temp /= 10;
  }

  int divisor = 1;

  for (int i = 1; i < digits; i++)
  {
    divisor *= 10;
  }

  while (divisor)
  {
    _putchar(n / divisor % 10 + '0');
    divisor /= 10;
  }

  return digits;
}

/**
 * _putuint - Writes an unsigned integer to stdout in the specified base.
 * @n: The integer to write.
 * @base: The base to use for conversion.
 * @digits: The string of digits for the specified base.
 *
 * Return: The number of digits written.
 */
int _putuint(unsigned int n, int base, char *digits)
{
  if (n == 0)
  {
    return _putchar('0');
  }

  int len = 0;

  while (n)
  {
    int digit = n % base;
    _putchar(digits[digit]);
    n /= base;
    len++;
  }

  return len;
}

/**
 * _printf - Writes formatted output to stdout.
 * @format: The format string.
 * @...: The optional arguments to format and write.
 *
 * Return: The number of characters written.
 */
int _printf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  int len = 0;

  while (*format)
  {
    if (*format == '%')
    {
      format++;

      switch (*format)
      {
        case 'c':
        {
          char c = va_arg(args, int);
          _putchar(c);
          len++;
          break;
        }

        case 's':
        {
          char *s = va_arg(args, char *);
          len += _putstr(s);
          break;
        }

        case '%':
        {
          _putchar('%');
          len++;
          break;
        }

        case 'd':
        case 'i':
        {
          int n = va_arg(args, int);
          len += _putint(n);
          break;
        }

        case 'b':
        {
          unsigned int n = va_arg(args, unsigned int);
          len += _putuint(n, 2, "01");
          break;
        }

        case 'u':
        {
          unsigned int n = va_arg(args, unsigned int);
          len += _putuint(n, 10, "0123456789");
          break;
        }
        case 'o': {
          unsigned int n = va_arg(args, unsigned int);
          len += _putuint(n, 8, "01234567");
          break;
        }
        case 'x': {
          unsigned int n = va_arg(args, unsigned int);
          len += _putuint(n, 16, "0123456789abcdef");
          break;
        }
        case 'X': {
          unsigned int n = va_arg(args, unsigned int);
          len += _putuint(n, 16, "0123456789ABCDEF");
          break;
        }
        default: {
          _putchar(*format);
          len++;
          break;
        }
      }
    } else {
      _putchar(*format);
      len++;
    }
    format++;
  }
  va_end(args);
  return len;
}       
