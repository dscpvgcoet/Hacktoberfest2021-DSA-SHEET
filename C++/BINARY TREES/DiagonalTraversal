#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node {
	int data;
	Node *left, *right;
};

vector<int> diagonal(Node* root)
{
	vector<int> diagonalVals;
	if (!root)
		return diagonalVals;

	// The leftQueue will be a queue which will store all
	// left pointers while traversing the tree, and will be
	// utilized when at any point right pointer becomes NULL

	queue<Node*> leftQueue;
	Node* node = root;

	while (node) {

		// Add current node to output
		diagonalVals.push_back(node->data);
		// If left child available, add it to queue
		if (node->left)
			leftQueue.push(node->left);

		// if right child, transfer the node to right
		if (node->right)
			node = node->right;

		else {
			// If left child Queue is not empty, utilize it
			// to traverse further
			if (!leftQueue.empty()) {
				node = leftQueue.front();
				leftQueue.pop();
			}
			else {
				// All the right childs traversed and no
				// left child left
				node = NULL;
			}
		}
	}
	return diagonalVals;
}

// Utility method to create a new node
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Driver program
int main()
{
	Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);

	/* Node* root = newNode(1);
			root->left = newNode(2);
			root->right = newNode(3);
			root->left->left = newNode(9);
			root->left->right = newNode(6);
			root->right->left = newNode(4);
			root->right->right = newNode(5);
			root->right->left->right = newNode(7);
			root->right->left->left = newNode(12);
			root->left->right->left = newNode(11);
			root->left->left->right = newNode(10);*/

	vector<int> diagonalValues = diagonal(root);
	for (int i = 0; i < diagonalValues.size(); i++) {
		cout << diagonalValues[i] << " ";
	}
	cout << endl;

	return 0;
}
