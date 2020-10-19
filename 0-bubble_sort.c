#include "sort.h"

int _putchar(char c);
/**
 * bubble_sort - function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(const int *array, size_t size)
{
	size_t step;
	size_t i;
	size_t j = 0;
	int temp;
	int *arri = (int *)array;

	if (size > 1)
	{
		for (step = 0; step < size - 1; ++step)
		{
			for (i = 0; i < size - step - 1; ++i)
			{
				if (array[i] > array[i + 1])
				{
					temp = array[i];
					arri[i] = array[i + 1];
					arri[i + 1] = temp;
					j = 0;
					while (arri && j < size)
					{
					if (j > 0)
					{
						_putchar(',');
						_putchar(' ');
					}
					print_number(arri[j]);
					++j;
					}
					_putchar('\n');
				}
			}
		}
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
