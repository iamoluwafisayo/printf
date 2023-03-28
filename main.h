#ifndef MAIN_H
#define MAIN_H

void print_char(va_list arg, int *count);

void print_str(va_list arg, int *count);

void print_percent(va_list arg, int *count);

int _printf(const char *format, ...);

#endif /* MAIN_H */
