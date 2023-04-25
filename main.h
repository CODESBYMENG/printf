#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#include <stddef.h> /* for NULL */

/* Function prototypes */
int _printf(const char *format, ...);
int parse_format(const char *format, va_list args);
/* ... */


int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_i(va_list args);
int print_b(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_S(va_list args);
int print_p(va_list args);
int print_r(va_list args);
int print_R(va_list args);

/**
 * struct conversion_specifier - Struct for conversion specifiers
 * @specifier: The conversion specifier
 * @f: The function associated with the conversion specifier
 *
 * Description: Contains the conversion specifier and the function pointer
 * to the function that handles the conversion.
 */
typedef struct conversion_specifier
{
    char specifier;
    int (*f)(va_list);
} conversion_t;

#endif /* MAIN_H */
