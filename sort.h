#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(const int *array, size_t size);
int _putchar(char c);
void print_number(int n);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *xp, int *yp);
void quick_sort(int *array, size_t size);
void quickSort(int array[], int low, int high, int size);
int partition(int array[], int low, int high);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int arr[], int n, int i);
void radix_sort(int *array, size_t size);
int getMax(int array[], int n);
void countingSort(int array[], int size, int place);

#endif /* SORT_H */
