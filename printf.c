

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <main.h>


void print_unsigned(unsigned int n, int base, int is_uppercase, int* count) {
    char digits[] = "0123456789abcdef";
    char digits_uppercase[] = "0123456789ABCDEF";
    char* chosen_digits = is_uppercase ? digits_uppercase : digits;

    if (n / base) {
        print_unsigned(n / base, base, is_uppercase, count);
    }
    putchar(chosen_digits[n % base]);
    (*count)++;
}

void print_pointer(void* p, int* count) {
    uintptr_t ptr_val = (uintptr_t)p;

    for (int i = (sizeof(uintptr_t) * 2) - 1; i >= 0; i--) {
        int shift = i * 4;
        unsigned int digit = (ptr_val >> shift) & 0xf;
        if (digit < 10) {
            putchar('0' + digit);
        }
        else {
            putchar('A' + digit - 10);  // Uppercase for hexadecimal
        }
        (*count)++;
    }
}
void print_int(int n, int* count) {
    if (n == INT_MIN) {
        fputs("-2147483648", stdout); // INT_MIN as a string
        *count += 11; // Length of "-2147483648"
        return;
    }
    if (n < 0) {
        putchar('-');
        (*count)++;
        n = -n;
    }
    if (n / 10) {
        print_int(n / 10, count);
    }
    putchar(n % 10 + '0');
    (*count)++;
}

// Updated _printf function with integer handling
int _printf(const char* format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            switch (format[i]) {
            case 'c': {
                char ch = (char)va_arg(args, int); // char is promoted to int
                putchar(ch);
                count++;
                break;
            }
            case 's': {
                char* str = va_arg(args, char*);
                if (str == NULL) str = "(null)";
                for (int j = 0; str[j] != '\0'; j++, count++) {
                    putchar(str[j]);
                }
                break;
            }
            case 'd':
            case 'i': {
                int num = va_arg(args, int);
                print_int(num, &count);
                break;
            }
            case 'u': {
                unsigned int num = va_arg(args, unsigned int);
                print_unsigned(num, 10, 0, &count);
                break;
            }
            case 'o': {
                unsigned int num = va_arg(args, unsigned int);
                print_unsigned(num, 8, 0, &count);
                break;
            }
            case 'x': {
                unsigned int num = va_arg(args, unsigned int);
                print_unsigned(num, 16, 0, &count);
                break;
            }
            case 'X': {
                unsigned int num = va_arg(args, unsigned int);
                print_unsigned(num, 16, 1, &count);
                break;
            }
            case 'p': {
                void* ptr = va_arg(args, void*);
                print_pointer(ptr, &count);
                break;
            }
            case '%': {
                putchar('%');
                count++;
                break;
            }
            default: {
                putchar(format[i]);
                count++;
                break;
            }
            }
        }
        else {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return count;
}