#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

int _putchar(char c);
int type_char(va_list ap);
int type_string(va_list ap);
int type_pourc(va_list ap);
int _printf(const char *format, ...);
int type_int(va_list ap);
int reverse_array(char* a, int n);

/**
 * struct select - points to where args
 * @select: strcutrue
 * @f: pointer
 */
typedef struct select
{
	char *select;
	int (*f)(va_list);
} type_select;

extern type_select toa[];

#endif
