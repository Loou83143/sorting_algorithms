#include "sort.h"

/**
 * iParent - Returns index of parent node for an array arranged as a binary
 * tree, for index i
 * @i: Starting index to determine parent node index
 * Return: Index of parent node
 */
int iParent(int i)
{
	return ((i - 1) / 2);
}

/**
 * iLeftChild- Returns index of left child branch for an array arranged as
 * a binary tree, for index i
 * @i: Starting index to determine left child branch index
 * Return: Index of left child node
 */
int iLeftChild(int i)
{
	return ((2 * i) + 1);
}

/**
 * ConvertToHeap - Arranges array of integers into a heap/binary tree scheme
 * @array: Array of integers
 * @size: Number of elements in array
 */
void ConvertToHeap(int *array, size_t size)
{
	int start;

	start = iParent(size - 1);

	while (start >= 0)
	{
		SiftDown(array, size, start, size - 1);
		start--;
	}
}

/**
 * SiftDown - Shuffles heap/binary tree sorted array into array sorted by
 * ascending value
 * @array: Array of values to be sorted in place, from heap to ascending
 * @size: Number of elements in array
 * @start: Starting index
 * @end: Ending index
 */
void SiftDown(int *array, size_t size, int start, int end)
{
	int root, swap, temp, child;

	root = start;

	while (iLeftChild(root) <= end)
	{
		child = iLeftChild(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts array of integers in ascending order using a heap sort
 * sift-down alogrithm
 * @array: Array of values to be sorted
 * @size: Number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	int iEnd, temp;

	if (!array || size < 2)
		return;

	ConvertToHeap(array, size);

	iEnd =  (int)size - 1;
	while (iEnd > 0)
	{
		temp = array[iEnd];
		array[iEnd] = array[0];
		array[0] = temp;
		print_array(array, size);
		iEnd--;
		SiftDown(array, size, 0, iEnd);
	}
}