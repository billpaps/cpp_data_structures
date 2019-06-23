#include <string>

using namespace std;

class MinHeap
{
protected:


public:

    int current_length;
    int *heap_arr;
    int heap_size;
    MaxHeap(); //Constructor
    ~MaxHeap();

    void insertKey(int k);

    void sift_down(int index);

    int parent(int n);

    int leftChild(int n);

    int rightChild(int n);

    int getMax();

    void swap(int *x, int *y);

    int get_size();

    void extract();

};
