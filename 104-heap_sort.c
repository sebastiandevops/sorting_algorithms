#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm.
 *
 * @array: array to be sorted.
 * @size: Size of the array
 *
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	size_t i, k;

	i = size / 2 - 1;
	while ((int)i >= 0)
	{
		heapify(array, size, i);
		i--;
	}
	i = size - 1;
	while ((int)i >= 0)
	{
		swap(&array[0], &array[i]);
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
		heapify(array, i, 0);
		i--;
	}
}

/**
 * heapify - Find largest among root, left child and right child.
 *
 * @arr: array to be checked.
 * @n: Size of the array
 * @i: index.
 * Return: void.
 */
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
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
