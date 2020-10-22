#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array to be sorted.
 * @size: Size of the array
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	size_t low = 0;

	quickSort(array, low, size - 1, size);
}

/**
 * partition - partition the array on the basis of pivot element
 *
 * @array: array to be sorted.
 * @low: left most Index
 * @high: Right most Index
 *
 * Return: void.
 */
int partition(int array[], int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	return (i + 1);
}

/**
 * quickSort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: array to be sorted.
 * @low: left most Index
 * @high: Right most Index
 * @size: size of array.
 *
 * Return: void.
 */
void quickSort(int array[], int low, int high, int size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quickSort(array, low, pi - 1, size);
		quickSort(array, pi + 1, high, size);
	}

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
