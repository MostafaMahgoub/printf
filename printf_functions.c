#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: the number of characters printed
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _strlen - calculates the length of a string
 * @str: the string to calculate the length of
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    return (len);
}

/**
 * print_integer - prints an integer
 * @n: the integer to print
 *
 * Return: the number of characters printed
 */
int print_integer(int n)
{
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }

    if (n / 10)
    {
        count += print_integer(n / 10);
    }

    count += _putchar((n % 10) + '0');

    return (count);
}

/**
 * print_unsigned - prints an unsigned integer in a given base
 * @n: the unsigned integer to print
 * @base: the base to print the integer in (e.g. 8 for octal, 16 for hexadecimal)
 * @uppercase: a flag indicating whether to print the letters in uppercase
 *
 * Return: the number of characters printed
 */
int print_unsigned(unsigned int n, int base, int uppercase)
{
    char buffer[32];
    int count = 0;
    int i = 0;

    do {
        int digit = n % base;
        buffer[i++] = (digit < 10) ? digit + '0' : digit + (uppercase ? 'A' : 'a') - 10;
        n /= base;
    } while (n != 0);

    for (i = i - 1; i >= 0; i--)
    {
        count += _putchar(buffer[i]);
    }

    return (count);
}

/**
 * print_special_string - prints a string, replacing non-printable characters with escape sequences
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int print_special_string(char *str)
{
    int count = 0;

    for (; *str; str++)
    {
        if (*str < 32 || *str >= 128)
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += print_unsigned(*str, 16, 1);
        }
        else
        {
            count += _putchar(*str);
        }
    }

    return (count);
}

/**
 * print_pointer - prints a void pointer as a hexadecimal number
 * @ptr: the pointer to print
 *
 * Return: the number of characters printed
 */
int print_pointer(void *ptr)
{
    int count = 0;

    count += _putchar('0');
    count += _putchar('x');
    count += print_unsigned((unsigned long)ptr, 16, 1);

    return (count);
}

/**
 * print_reversed - prints a string in reverse order
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int print_reversed(char *str)
{
    int count = 0;
    int len = _strlen(str);
    int i;

    for (i = len - 1; i >= 0; i--)
    {
        count += _putchar(str[i]);
    }

    return (count);
}

/**
 * print_rot13 - prints a string using the rot13 cipher
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int print_rot13(char *str)
{
    int count = 0;

    while (*str != '\0')
    {
        if ((*str >= 'a' && *str <= 'm') || (*str >= 'A' && *str <= 'M'))
        {
            count += _putchar(*str + 13);
        }
        else if ((*str >= 'n' && *str <= 'z') || (*str >= 'N' && *str <= 'Z'))
        {
            count += _putchar(*str - 13);
        }
        else
        {
            count += _putchar(*str);
        }

        str++;
    }

    return (count);
}

/**
 * print_binary - prints an unsigned integer in binary format
 * @n: the unsigned integer to print
 *
 * Return: the number of characters printed
 */
int print_binary(unsigned int n)
{
    int count = 0;
    int i;
    char buffer[32];

    if (n == 0)
    {
        return (_putchar('0'));
    }

    for (i = 0; n > 0; i++)
    {
        buffer[i] = (n % 2 == 0) ? '0' : '1';
        n /= 2;
    }

    for (i = i - 1; i >= 0; i--)
    {
        count += _putchar(buffer[i]);
    }

    return (count);
}
