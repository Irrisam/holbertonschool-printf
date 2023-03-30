#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

/**
 *  *  *  * _putchar - writes the character c to stdout
 *   *   *   * @c: The character to print
 *    *    *    *
 *     *     *     * Return: On success 1.
 *      *      *      * On error, -1 is returned, and errno is set appropriately.
 *       *       *       */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *  * type_char - convert to char
 *   *
 *    * @ap: arguments parameters
 *     *
 *      * Return: print char
 *       */
int type_char(va_list ap)
{
	int stock;

	stock = va_arg(ap, int);

	if (stock == 0)
	{
		stock = 0;
	}
	return(write (1, &stock, 1));
}

/**
 *  * type_string - convert to string
 *   *
 *    * @ap: arguments parameters
 *     *
 *      * Return: print string
 *       */
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
 *  * type_pourc - print %
 *   *
 *    * @ap: arguments parameters
 *     *
 *      * Return: print %
 *       */
int type_pourc(va_list ap)
{
	char stock = '%';
	(void) ap;

	return (write(1, &stock, 1));
}


/**
 *  * _printf - convert arguments and print them
 *   *
 *    * @format: list of types of arguments
 *     * passed to the function
 *      *
 *       * Return: string + convert arg
 *        */
int _printf(const char *const format, ...)
{
	va_list ap;

	int count =  0;
	unsigned int compteur1 = 0;
	unsigned int compteur2 = 0;
	unsigned int scanlen = 0;

	type_select toa[] = {
		{"c", type_char},
		{"s", type_string},
		{"%", type_pourc},
		{"\0", NULL}
	};


	va_start(ap, format);
	scanlen = strlen(format);

	while (format[compteur1] != '\0')
	{
		if ((format[compteur1] == '%' && format[compteur1 + 1] == '\0' && scanlen <= compteur1) || format == NULL)
		{
			return (-1);
		}

		if (format[compteur1] == '%')
		{

			compteur2 = 0;
			for ( ; *toa[compteur2].select != '\0'; compteur2++)
			{
				if (format[compteur1 + 1] != 'c' && format[compteur1 + 1] != 's' && format[compteur1 + 1] != '%')
				{
					write(1, "%", 1);
					compteur1++;
					break;
				}
				if (format[compteur1 + 1] == *toa[compteur2].select)
				{
					count += toa[compteur2].f(ap);
					compteur1 +=2;
					break;
				}
			}
		}
		if (format[compteur1] != '\0' && format[compteur1] != '%' && scanlen >= compteur1)
		{
			count += write(1, &format[compteur1], 1);
			compteur1++;
		}
	}
	va_end(ap);
	return (count);
}
