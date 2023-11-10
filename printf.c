#include <stdarg.h>
#include <stdio.h>

void print_int(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        print_int(n / 10);
    }
    putchar(n % 10 + '0');
}

int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            switch (format[i]) {
                case 'c': {
                    char ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    if (str == NULL) str = "(null)";
                    for (int j = 0; str[j] != '\0'; j++, count++) {
                        putchar(str[j]);
                    }
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    int temp_count = 0;
                    if (num < 0) {
                        temp_count++;
                    }
                    int temp_num = num;
                    do {
                        temp_count++;
                        temp_num /= 10;
                    } while (temp_num != 0);
                    print_int(num);
                    count += temp_count;
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default: {
                    putchar('%');
                    putchar(format[i]);
                    count += 2;
                    break;
                }
            }
        } else {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return count;
}
