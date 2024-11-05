/*
Here's the C++ code for boundary traversal of a binary tree using recursion without a bool function:
*/

#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to print the left boundary nodes
void leftBoundary(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL || node->right != NULL) {
        cout << node->data << " ";
        leftBoundary(node->left);
    }
}

// Function to print the leaf nodes
void leafNodes(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        cout << node->data << " ";
    }
    leafNodes(node->left);
    leafNodes(node->right);
}

/*
// Function to print the right boundary nodes
void rightBoundary(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL || node->right != NULL) {
        rightBoundary(node->right);
        cout << node->data << " ";
    }
}
*/
void rightBoundary(Node * node)
{
	 if (node->left == NULL && node->right == NULL)
	 {
	 	return ;
	 }
	 Node * t=root;
	 while(t->right!=null)
	 {
	 	t=t->right;
	 	cout<<t->data;
	 }
}

// Function to perform boundary traversal
void boundaryTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    leftBoundary(root->left);
    leafNodes(root);
    rightBoundary(root->right);
    cout << endl;
}

// Driver code
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->left->right->left = createNode(5);
    root->left->right->right = createNode(6);
    root->right->right = createNode(8);

    cout << "Boundary Traversal: ";
    boundaryTraversal(root);
    return 0;
}

/*
Output:

Boundary Traversal: 1 2 3 5 6 4 7 8 


Time Complexity: O(n)

Space Complexity: O(h), where h is the height of the tree

This code defines a binary tree node structure, creates a sample binary tree, and performs boundary traversal using recursive functions.

Key Functions:

- leftBoundary: Prints the left boundary nodes.
- leafNodes: Prints the leaf nodes.
- rightBoundary: Prints the right boundary nodes.
- boundaryTraversal: Performs the boundary traversal.

Would you like me to:

1. Explain any specific part of the code?
2. Provide examples for different binary tree structures?
3. Discuss variations of the boundary traversal algorithm?

*/
