#include <string>

using namespace std;

class MaxHeap
{

public:

    int* heap_arr;
	int heap_size, current_length;

	MaxHeap(); //Constructor
	~MaxHeap();

	void insertKey(int k);

	void Heapify();

	int parent(int n);

	int leftChild(int n);

	int rightChild(int n);

	int getMax();

	void swap(int* x, int* y);

	int get_size();

	void extract();

	void siftdown(int i);

	bool isLeaf(int i);

};
