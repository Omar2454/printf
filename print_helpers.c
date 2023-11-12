#include "main.h"


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