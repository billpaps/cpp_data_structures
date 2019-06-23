
class AvlTree
{
public:
	int key, height_num, currentSize;
	AvlTree* left_child;
	AvlTree* right_child;
	AvlTree* node;


	int max(int x, int y);

	int height(AvlTree *node);

	AvlTree* new_node(int key);

	AvlTree *left_rotate(AvlTree *node);

	AvlTree *right_rotate(AvlTree *node);

	int balance(AvlTree *node);

	AvlTree* insert_node(AvlTree* node, int key);

	void print_tree(AvlTree *root);

	int get_size();

};
