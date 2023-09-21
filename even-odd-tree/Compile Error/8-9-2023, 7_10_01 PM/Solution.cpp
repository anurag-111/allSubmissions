// https://leetcode.com/problems/even-odd-tree

// Store this code
// C++ code for Minimize changes to convert into Tree with root 1, even left
// children and odd right children

#include <bits/stdc++.h>
using namespace std;

// To store the final changes needed
int changes;

struct Node {
	int value;
	struct Node *left, *right;
};

// Utility function to create new
// tree node
Node* newNode(int data) {
	Node* temp = new Node;
	temp->value = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Conditions :
// The root node is always 1.
// Every left child of a node is always even.
// Every right child of a node is always odd. 

void helper(Node *root) {
    if(root == NULL) {
        return;
    }
    
    if(root->left && (root->left->value % 2) != 0) {
        changes++;
        root->left->value -= 1;
    }
    
    if(root->right && (root->right->value % 2) == 0) {
        changes++;
        root->left->value -= 1;
    }
    
    helper(root->left);
    helper(root->right);
}

int minCount(Node *root) {
    changes = 0;
    
    if(root == NULL) {
        return changes;
    }
    
    if(root->value != 1) {
        changes += root -> value - 1;
        root -> value = 1;
    }
    
    helper(root);
    return changes;
}




// Driver Code
int main()
{

	// Taking input
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(2);
	root->left->left = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(8);

	// Function call
	cout << minCount(root) << endl;

	return 0;
}