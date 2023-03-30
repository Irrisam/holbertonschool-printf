#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * type_char - convert to char
 *
 * @ap: arguments parameters
 *
 * Return: print char
 */
int type_char(va_list ap)
{
	int stock;

	stock = va_arg(ap, int);

	if (stock == 0)
	{
		stock = 0;
	}
	return (write(1, &stock, 1));
}

/**
 * type_string - convert to string
 *
 * @ap: arguments parameters
 *
 * Return: print string
 */
int type_string(va_list ap)
{
	char *stock;

	stock = va_arg(ap, char*);

	if (stock == 0)
	{
		stock = "(null)";
	}
	return (write(1, stock, strlen(stock)));
}

/**
 * type_pourc - print %
 *
 * @ap: arguments parameters
 *
 * Return: print %
 */
int type_pourc(va_list ap)
{
	char stock = '%';
	(void) ap;

	return (write(1, &stock, 1));
}
