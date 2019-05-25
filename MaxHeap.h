#include <string>

using namespace std;

class MaxHeap
{

	int* heap_arr;
	int heap_size, current_length;

public:

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

	void extract(int* del);

};
