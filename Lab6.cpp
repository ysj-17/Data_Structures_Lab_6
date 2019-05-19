// Program Name: Lab6
//
// Description:  
//  Using rotations to make a complete tree from a degenerate tree
//
// What's on your mind about this lab?
//  This was hard... I couldn't think of a way to do rotations automatically
//	I had to do rotations by hand or call the rotation functions by hand
//  
// Author: Jason Yoon
//
// Date: 8/4/2018
//
// IDE Used: Visual Microsoft
//


#include <iostream>
#include "BinaryTree.h"
using namespace std;


template <typename T>
void printPreorder(TreeNode<T> *&node);
template <typename T>
void singleLeftRotate(TreeNode<T> *&tree);
template <typename T>
void singleRightRotate(TreeNode<T> *&tree);
template <typename T>
void leftPartRotatations(TreeNode<T> *&tree);
template <typename T>
void rightPartRotatations(TreeNode<T> *&tree);


int main() {


	BinarySearchTree<int> bst;

	for (int index = 1; index <= 9; index++)
		bst.insert(index, bst.root);

	cout << "Set binary tree to hold values 1 through 9" << endl;
	cout << "The number of Nodes is 9" << endl;
	cout << "Root is set to 1, but rotations will"
			<< " set root to 5 which is 2*2+1" << endl;
	cout << "This is pre-order before rotations: ";
	printPreorder(bst.root);
	cout << endl;

	cout << endl << "--- Will now start rotating ---" << endl;
	
	cout << endl << "Rotating to new root: \t\t";
	for (int index = 0; index < 4; index++) 
		singleLeftRotate(bst.root); // call function 4 times
	printPreorder(bst.root);
	cout << endl;

	cout << "Rotating left side of tree: \t";
	leftPartRotatations(bst.root);
	printPreorder(bst.root);
	cout << endl;

	cout << "Rotating right side of tree: \t";
	rightPartRotatations(bst.root);
	printPreorder(bst.root);
	cout << endl;

	cin.get();
	return 0;
}


template <typename T>
void singleLeftRotate(TreeNode<T> *&tree)
{
	TreeNode<T> *t1 = tree->right;
	TreeNode<T> *t2 = t1->left;
		
	t1->left = tree;
	tree->right = t2;
	tree = t1;
}


template <typename T>
void singleRightRotate(TreeNode<T> *&tree)
{
	TreeNode<T> *t1 = tree->left->left;
	TreeNode<T> *t2 = t1->right;

	t1->right = tree->left;
	tree->left->left = t2;
	tree->left = t1;
}


template <typename T>
void leftPartRotatations(TreeNode<T> *&tree) 
{
	for (int index = 0; index < 2; index++)
		singleRightRotate(tree);

	// left rotate once to complete the rotations on the right side
	singleLeftRotate(tree->left->right);

}


template <typename T>
void rightPartRotatations(TreeNode<T> *&tree) 
{
	for (int index = 0; index < 2; index++)
		singleLeftRotate(tree->right); // calls left rotate 2 times 
		// but passes the tree right node as the root
}


template <typename T>
void printPreorder(TreeNode<T> *&node)
{
	if (node == NULL)
		return;

	cout << node->data << " ";

	printPreorder(node->left);

	printPreorder(node->right);
}







