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
	int max, i, k;

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
	free(count);
	free(output);
}
