#ifndef PRINTF_FUNCTIONS_H
#define PRINTF_FUNCTIONS_H

int _putchar(char c);
int _strlen(char *str);
int print_integer(int n);
int print_unsigned(unsigned int n, int base, int uppercase);
int print_special_string(char *str);
int print_pointer(void *ptr);
int print_reversed(char *str);
int print_rot13(char *str);

#endif /* PRINTF_FUNCTIONS_H */
