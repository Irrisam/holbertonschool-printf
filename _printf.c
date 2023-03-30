#include "main.h"

int _printf(const char *const format, ...)
{
	va_list ap;
	unsigned int count =  0, compteur1 = 0, compteur2 = 0, scanlen = 0;
	type_select toa[] = {
		{"s", type_string},
		{"d", type_int},
		{"i", type_int},
		{"%", type_pourc},
		{"\0", NULL}
	};

	va_start(ap, format);
	if (format == NULL || (format[compteur1] == '%' &&
				format[compteur1 + 1] == '\0'))
		return (-1);
	scanlen = strlen(format);
	while (format[compteur1] != '\0')
	{
		if (format[compteur1] == '%')
		{
			compteur2 = 0;
			for ( ; *toa[compteur2].select != '\0'; compteur2++)
			{
				if (format[compteur1 + 1] != 'c' && format[compteur1 + 1] != 's'
						&& format[compteur1 + 1] != '%' && format[compteur1 + 1] != 'd' && format[compteur1 + 1] != 'i')
				{
					count += write(1, "%", 1);
					compteur1++;
					break;
				}
				if (format[compteur1 + 1] == *toa[compteur2].select)
				{
					count += toa[compteur2].f(ap);
					compteur1 += 2;
					break;
				}
				if (format[compteur1 + 1] == *toa[compteur2].select)
				{
					count += toa[compteur2].f(ap);
					compteur1 += 2;
					break;
				}
			}
		}
		if (format[compteur1] != '\0' && format[compteur1] != '%' &&
				scanlen >= compteur1)
		{
			count += write(1, &format[compteur1], 1);
			compteur1++;
		}
	}
	va_end(ap);
	return (count);
}
