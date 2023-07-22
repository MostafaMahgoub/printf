#include "main.h"
#include "printf_functions.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints output according to a format
 * @format: character string containing format specifier
 *
 * Return: number of characters printed (excluding null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    int count = 0;
    const char *temp;
    va_list arg;
    char *str;

    va_start(arg, format);
    for (temp = format; format && *temp != '\0'; temp++)
    {
        if (*temp == '%')
        {
            temp++;
            switch (*temp)
            {
                case 'c':
                    count += write(1, &va_arg(arg, int), 1);
                    break;
                case 's':
                    str = va_arg(arg, char *);
                    if (!str)
                    {
                        str = "(null)";
                    }
                    count += write(1, str, _strlen(str));
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                case 'd':
                case 'i':
                    count += print_integer(va_arg(arg, int));
                    break;
                case 'b':
                    count += print_binary(va_arg(arg, unsigned int));
                    break;
                case 'u':
                    count += print_unsigned(va_arg(arg, unsigned int), 10, 0);
                    break;
                case 'o':
                    count += print_unsigned(va_arg(arg, unsigned int), 8, 0);
                    break;
                case 'x':
                    count += print_unsigned(va_arg(arg, unsigned int), 16, 0);
                    break;
                case 'X':
                    count += print_unsigned(va_arg(arg, unsigned int), 16, 1);
                    break;
                case 'S':
                    str = va_arg(arg, char *);
                    if (!str)
                    {
                        str = "(null)";
                    }
                    count += print_special_string(str);
                    break;
                case 'p':
                    count += print_pointer(va_arg(arg, void *));
                    break;
                case 'r':
                    str = va_arg(arg, char *);
                    if (!str)
                    {
                        str = "(null)";
                    }
                    count += print_reversed(str);
                    break;
                case 'R':
                    str = va_arg(arg, char *);
                    if (!str)
                    {
                        str = "(null)";
                    }
                    count += print_rot13(str);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, &(*temp), 1);
                    break;
            }
        }
        else
        {
            count += write(1, &(*temp), 1);
        }
    }
    va_end(arg);

    return (count);
}
