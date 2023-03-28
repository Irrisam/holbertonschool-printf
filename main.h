#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 *  * _putchar - writes the character c to stdout
 *   * @c: The character to print
 *    *
 *     * Return: On success 1.
 *      * On error, -1 is returned, and errno is set appropriately.
 *       */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 *  * struct select - points to where args
 *   * @select: strcutrue
 *    * @f: pointer
 *    */
typedef struct select
{
	char *select;
	void (*f)(va_list);
} type_select;


#endif
