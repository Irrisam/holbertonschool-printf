#include "main.h"

/**
 * reverse_array - a function that reverses the content
 * of an array of integers
 *
 * @a: array of integers to reverse
 * @n: the numer of elements to swap
 *
 * Return: 0
 */
int reverse_array(char* a, int n)
{
	int compteur = 0;
	int temp = 0;
	int size = n;
	n = n - 1;
	while (compteur < n)
	{
		temp = a[compteur];
		a[compteur] = a[n];
		a[n] = temp;
		n--;
		compteur++;
	}
	return(write(1, a , size));
}

/**
 * type_int - convert to int
 *
 * @ap: arguments parameters
 *
 * Return: print int
 */
int type_int(va_list ap)
{
	char * returnarray = NULL;
	int compteur = 0;
	long int stock = va_arg(ap, int);
	int size;
	int temp = 0;
	int count = stock;
	int minuscorrect = 0;

	if (stock == 0)
	{
		minuscorrect += (write(1, "0", 1));
		return (minuscorrect);
	}
	if (stock < 0)
	{
		minuscorrect = 1;
		write(1, "-", 1);
		stock = -stock;
	}
	while(count)
	{
		count /= 10;
		temp ++;
	}
	size = temp;

	returnarray = malloc(size * sizeof(char));
	if (returnarray == NULL)
	{
		return (0);
	}
	for (; compteur < size; compteur++)
	{
		temp = stock %10;
		temp = temp + '0';
		stock = stock / 10;
		returnarray[compteur] = temp;
	}
	minuscorrect += reverse_array(returnarray, size);
	return (minuscorrect);
}
