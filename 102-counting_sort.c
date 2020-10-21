#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 *
 * @array: array to be sorted.
 * @size: Size of the array
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	int *output = (int *) malloc(sizeof(array[0]) * size);
	int *count;
	size_t max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > (int)max)
		max = array[i];
	}
	count = (int *) malloc(sizeof(array[0]) * size);
	for (i = 0; i <= max; ++i)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	i = size - 1;
	while (i != 0)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
		i--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
