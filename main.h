#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(va_list arg_list);
int print_string(va_list arg_list);
int print_int(va_list arg_list);
int print_uint(va_list arg_list);
int print_uint_to_octal(va_list arg_list);
int print_uint_to_hex(va_list arg_list, char format_specifier);
int print_uint_to_binary(va_list arg_list);
int print_custom_string(va_list arg_list);
int print_pointer(va_list arg_list);
int print_rev(va_list arg_list);
int print_rot13(va_list arg_list);

#endif /* _MAIN_H_ */
