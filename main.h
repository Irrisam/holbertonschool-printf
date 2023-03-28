#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int type_char(va_list ap);
int type_string(va_list ap);
int type_pourc(va_list ap);
int _printf(const char * format, ...);

/**
 *  * struct select - points to where args
 *   * @select: strcutrue
 *    * @f: pointer
 *    */
typedef struct select
{
	char *select;
	int (*f)(va_list);
} type_select;

#include <unistd.h>

/**
 *  * _putchar - writes the character c to stdout
 *   * @c: The character to print
 *    *
 *     * Return: On success 1.
 *      * On error, -1 is returned, and errno is set appropriately.
 *       */


#endif
