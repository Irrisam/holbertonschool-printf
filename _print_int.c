#include "main.h"

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

int type_int(va_list ap)
{
	char * returnarray = NULL;
	  int compteur = 0;
	    int stock = va_arg(ap, int);
	      int size;
	        int temp = 0;
		  int count = stock;

		  if (stock == 0)
		  {
			    return (write(1, "00", 2));
		  }
		  if (stock < 0)
		  {
			    write(1, "-", 1);
			    if (stock == INT_MIN)
			    {
				     stock = INT_MAX; 
			    }
			    else
			    {
				    stock = -stock;
			    }
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
		  return(reverse_array(returnarray, size));
}
