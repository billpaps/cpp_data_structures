#include <string>

using namespace std;

class MinHeap
{
protected:
    int *heap_arr;
    int heap_size, current_length;

public:

    MinHeap(); //Constructor
	~MinHeap();

    void insertKey(int k);

    void sift_down(int index);

    int parent(int n);

    int leftChild(int n);

    int rightChild(int n);

    int getMin();

    void swap(int *x, int *y);

	int get_size();

    void extract();

};
