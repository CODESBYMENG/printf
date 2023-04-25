#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
unsigned int print_uint_to_octal(unsigned int n);
unsigned int print_uint_to_hex(unsigned int n, int lowercase);
unsigned int print_uint_to_binary(unsigned int n);
int print_char(va_list args);
int print_str(va_list args);
int print_int(va_list args);
int print_unsigned_int(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int lowercase);
int print_pointer(va_list args);
int print_rot13(va_list args);
int print_rev(va_list args);
int print_custom(va_list args, char c);

#endif /* MAIN_H */