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
