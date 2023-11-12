#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int _printf(const char* format, ...);
void print_unsigned(unsigned int n, int base, int is_uppercase, int* count);
void print_pointer(void* p, int* count);
void print_int(int n, int* count);

#endif // MAIN_H
