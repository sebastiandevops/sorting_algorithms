#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending
 * order using the radix_sort algorithm
 *
 * @array: array to be sorted.
 * @size: Size of the array
 *
 * Return: void.
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int place;

	for (place = 1; max / place > 0; place *= 10)
		countingSort(array, size, place);
}

/**
 * getMax - get the largest element from an array.
 * order using the radix_sort algorithm
 *
 * @array: array to be sorted.
 * @n: Size of the array
 *
 * Return: max.
 */
int getMax(int array[], int n)
{
	int max = array[0];
	int i;

	for (i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - get the largest element from an array.
 * order using the radix_sort algorithm
 *
 * @array: array to be sorted.
 * @size: Size of the array
 * @place: place to insert sorted element.
 * Return: void.
 */
void countingSort(int array[], int size, int place)
{
	int *output;
	int *count;
	int max;
	int i, k;

	max = (array[0] / place) % 10;
	output = (int *) malloc(sizeof(array[0]) * size + 1);
	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
		max = array[i];
	}
	count = (int *) malloc(sizeof(array[0]) * max + 1);

	for (i = 0; i < max; ++i)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
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

