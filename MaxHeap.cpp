#include "MaxHeap.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>

using namespace std;

MaxHeap::MaxHeap()
{
	heap_arr = new int[10];
	current_length = 0;
	heap_size = 10;
}

MaxHeap::~MaxHeap() {
	delete[] heap_arr;
}


int MaxHeap::parent(int n) { return (n - 1) / 2; }  // index of parent

int MaxHeap::leftChild(int n) { return n * 2 + 1; }  // index of leftChild

int MaxHeap::rightChild(int n) { return n * 2 + 2; }  // index of rightChild

void MaxHeap::swap(int* x, int* y) {
	int temporary = *x;
	*x = *y;
	*y = temporary;
}

void MaxHeap::insertKey(int k)
{
	if (heap_size == current_length) // Avoid overflow
	{
		int* tempora = new int[2 * heap_size];
		heap_size *= 2;

		for (int i = 0; i < heap_size; i++)
		{
			tempora[i] = heap_arr[i];
		}

		delete[] heap_arr;
		heap_arr = tempora;

	}

	int i = current_length;
	heap_arr[i] = k;

	while (i != 0 && heap_arr[parent(i)] < heap_arr[i])   // Fix the maxheap property
	{
		swap(&heap_arr[i], &heap_arr[parent(i)]);
		i = parent(i);
	}
	current_length++;
}


int MaxHeap::getMax()
{
	return heap_arr[0];
}


// ORDERING
void MaxHeap::Heapify()
{
	int worst_case = floor(log2(heap_size));  // height of the tree. Worst case scenario
	for (int i = 0; i < worst_case; i++)
	{
		int currentSize = 0;
		int starting_point = heap_arr[current_length / 2];

		while (starting_point >= 0)
		{
			int maximum = starting_point;
			int left = leftChild(starting_point);
			if (rightChild(starting_point) < heap_size)
			{
				int right = rightChild(starting_point);
				if (heap_arr[starting_point] < heap_arr[right])  // sometimes there is no right child so we will avoid IndexOutOfRange
				{
					maximum = right;
				}
			}

			if (heap_arr[starting_point] < heap_arr[left] && heap_arr[left] > heap_arr[maximum]) // in case right child is smaller than the left child
			{
				maximum = left;
			}

			if (maximum != starting_point)  // Change only if the parent is greater than at least one child (if the 2 childs are smaller than maximum will store the maximum of the two)
			{
				swap(&heap_arr[maximum], &heap_arr[starting_point]);
				currentSize++;
			}
			starting_point--;
		}
		if (currentSize == 0) // Means that the Heap has been Heapified
		{
			break;
		}

	}

}

int MaxHeap::get_size()
{
	return current_length;
}

void MaxHeap::extract(int* del)
{

}
