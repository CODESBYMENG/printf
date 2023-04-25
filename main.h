#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

int _putchar(char c);
int _printf(const char *format, ...);

/* Functions for handling different format specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hex_upper(va_list args);
int print_binary(va_list args);

/* Utility function */
int num_len(unsigned int num, int base);

/* Struct to hold a format specifier and its corresponding function */
typedef struct format_specifier
{
    char spec;
    int (*func)(va_list);
} format_t;

#endif /* MAIN_H */
