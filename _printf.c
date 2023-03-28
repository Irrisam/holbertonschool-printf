#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 *  *  * _putchar - writes the character c to stdout
 *   *   * @c: The character to print
 *    *    *
 *     *     * Return: On success 1.
 *      *      * On error, -1 is returned, and errno is set appropriately.
 *       *       */
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
	int stock = va_arg(ap, int);

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
	int scanlen = 0;
	char *stock;

	stock = va_arg(ap, char*);

	scanlen = strlen(stock);
	return (write(1, stock, scanlen));
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


/**
 * _printf - convert arguments and print them
 *
 * @format: list of types of arguments
 * passed to the function
 *
 * Return: string + convert arg
 */
int _printf(const char *const format, ...)
{
	va_list ap;

	int count =  0;
	unsigned int compteur1 = 0;
	unsigned int compteur2 = 0;

	type_select toa[] = {
		{"c", type_char},
		{"s", type_string},
		{"%", type_pourc},
		{'\0', NULL}
	};


	va_start(ap, format);
	if (format[compteur1] == '%' && format[compteur1 + 1] != 0)
	{
		return (-1);
	}

	for ( ; format[compteur1] != '\0'; compteur1++)
	{
		if (format[compteur1] == '%')
		{
			for ( ; compteur2 <= 5; compteur2++)
				if (format[compteur1 + 1] == *toa[compteur2].select)
				{
					count += toa[compteur2].f(ap);
					compteur1 += 2;
					break;
				}
			compteur2 = 0;
		}
		if (format[compteur1] != '\0')
		{
			count += write(1, &format[compteur1], 1);
		}
	}
	va_end(ap);
	return (count);
}
