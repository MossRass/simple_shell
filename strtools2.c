#include "holberton.h"


/**
 * _puts - funct to write str to standard out
 * @str: str to write
 */

void _puts(char *str)
{
	while (*str  != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

/**
 * prstr - prints str from arg
 * @args: arg pointer
 *
 * Return: count of str elements printed
 */
int prstr(va_list *args)
{
	int x = 0;
	char *ar;

	ar = va_arg(*args, char *);
	while (*ar != '\0')
	{
		_putchar(*ar);
		x++;
		ar++;
	}
	return (x);
}
/**
 * _putchar - writes the char c to str
 * @c: The char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(2, &c, 1));
}
