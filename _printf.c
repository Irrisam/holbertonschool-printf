#include "main.h"
/**
 * _printf - prints things thanks to external adapted functions,
 * keeping count of printed bytes
 *@format: given string containing indications for adapted functions
 *Return: count..
 */
int _printf(const char *const format, ...)
{
	va_list ap;

	type_select toa[] = {
		{"c", type_char},
		{"s", type_string},
		{"i", type_int},
		{"d", type_int},
		{"%", type_pourc},
		{"\0", NULL}
	};

	int counter1 = 0;
	int count = 0;

	va_start(ap, format);
	if (format == NULL)
		return (-1);

	for (; format[counter1] != '\0'; counter1++)
	{
		if (format[counter1] != '%')
		{
			count += write(1, &format[counter1], 1);
			continue;
		}
		counter1++;
		if (format[counter1] == '\0')
			return (-1);

		if (format[counter1] == '%')
		{
			count += write(1, "%", 1);
			continue;
		}

		int counter2 = 0;

		while (toa[counter2].select != NULL)
		{
			if (format[counter1] == *toa[counter2].select)
			{
				count += toa[counter2].f(ap);
				break;
			}
			counter2++;
		}
	}
	va_end(ap);
	return (count);
}
