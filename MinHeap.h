#include <string>

using namespace std;

class MinHeap
{
protected:
    int *heap_arr;
    int heap_size;

public:

    int current_length;
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

    void extract(MinHeap *heap_arr);

};
