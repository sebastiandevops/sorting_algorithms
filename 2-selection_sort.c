#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: array to be sorted.
 * @size: Size of the array
 *
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min_idx;
	size_t k;

	if (size <= 1)
		return;
	{
		for (i = 0; i < size - 2; i++)
		{
			min_idx = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min_idx])
					min_idx = j;
			}
			if (&array[min_idx] != &array[i])
			{
				swap(&array[min_idx], &array[i]);
				k = 0;
				while (array && k < size)
				{
					if (k > 0)
					{
						_putchar(',');
						_putchar(' ');
					}
					print_number(array[k]);
					k++;
				}
				_putchar('\n');
			}
		}
	}
}

/**
 * swap - function that swap elements
 *
 * @xp: element to be swaped.
 * @yp: element to be swaped.
 *
 * Return: void.
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

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
 * print_number - function that prints an integer..
 * @n: number of times that the diagonal will be printed.
 *
 *
 * Return: void.
 *
 */
void print_number(int n)
{
	int cont;
	int aux;

	if (n < 0)
	{
		_putchar('-');
		aux = n;
		cont = -1;
		while (aux < -9)
		{
			aux = (aux / 10);
			cont = (cont * 10);
		}
		while (cont <= -1)
		{
			_putchar((n / cont) + '0');
			n = (n % cont);
			cont = (cont / 10);
		}
	}
	else
	{
		aux = n;
		cont = 1;
		while (aux > 9)
		{
			aux = (aux / 10);
			cont = (cont * 10);
		}
		while (cont >= 1)
		{
			_putchar((n / cont) + '0');
			n = (n % cont);
			cont = (cont / 10);
		}
	}
}
