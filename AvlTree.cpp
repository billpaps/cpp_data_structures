#include "AvlTree.h"
#include <string>
#include <iostream>

using namespace std;

int AvlTree::max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	return y;
}

int AvlTree::height(AvlTree *node) //height of a node
{
	if (node == NULL)
	{
		return 0;
	}
	return node->height_num;
}

AvlTree* AvlTree::new_node(int key) {
    AvlTree* node = new AvlTree();
	node->key = key;
	node->right_child = NULL;
	node->left_child = NULL;
	node->height_num = 1;
    node->currentSize = 1;

    return (node);
}

//RIGHT ROTATE
AvlTree *AvlTree::right_rotate(AvlTree *nodey)
{
	AvlTree *x = nodey->left_child;
	AvlTree *right_leaf = x->right_child;

	// Rotate
	x->right_child = nodey;
	nodey->left_child = right_leaf;


	nodey->height_num = max(height(nodey->left_child), height(nodey->right_child)) + 1;

	x->height_num = max(height(x->left_child), height(x->right_child)) + 1;

	return x;

}//LEFT ROTATE
AvlTree* AvlTree::left_rotate(AvlTree* nodex)
{
	AvlTree* y = nodex->right_child;
	AvlTree* T2 = y->left_child;

	// Rotate
	y->left_child = nodex;
	nodex->right_child = T2;

	// New heights
	nodex->height_num = max(height(nodex->left_child), height(nodex->right_child)) + 1;
	y->height_num = max(height(y->left_child), height(y->right_child)) + 1;

	// New root
	return y;

}

//GET BALANCE OF NODE
int AvlTree::balance(AvlTree* node)
{
	if (node == NULL)
	{
		return 0;
	}
	int diff = height(node->left_child) - height(node->right_child); //height difference
	return diff;
}

//INSERTING NEW NODE
AvlTree* AvlTree::insert_node(AvlTree* node, int key)
{
	if (node == NULL) // first node
	{
		return(new_node(key));
	}

	if (key < node->key) //going to the left subtree
	{
		node->left_child = insert_node(node->left_child, key);
	}
	else if (key > node->key) //going to the right subtree
	{
		node->right_child = insert_node(node->right_child, key);
	}
	else // in bst we dont have equal keys
	{
		return node;
	}

	node->height_num = max(height(node->left_child), height(node->right_child)) + 1; //update the balance of the node

	int node_balance = balance(node);
    cout << endl << "node balance :" << node_balance<< endl;

	// There are 4 cases
	//1st case Left-Left Rotation
	if (node_balance > 1 && key < node->left_child->key)
	{
		return right_rotate(node);
	}
	//2nd case Left-Right
	if (node_balance > 1 && key > node->right_child->key)
	{
		node->left_child = left_rotate(node->left_child);
		return right_rotate(node);
	}
	//3rd case Right-Left
	if (node_balance < -1 && key < node->left_child->key)
	{
		node->right_child = right_rotate(node->right_child);
		return left_rotate(node);
	}
	//4th case Right-Right
	if (node_balance < -1 && key > node->right_child->key)
	{
		return right_rotate(node);
	}

	currentSize++;

	return node;//this node pointer has not been changed

}

//GO THROUGH THE TREE AND PRINT IT
void AvlTree::print_tree(AvlTree* root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		print_tree(root->left_child);
		print_tree(root->right_child);
	}
}

//RETURN SIZE
int AvlTree::get_size()
{
	return node->currentSize;
}
