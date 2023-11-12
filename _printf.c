

#include "main.h"


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