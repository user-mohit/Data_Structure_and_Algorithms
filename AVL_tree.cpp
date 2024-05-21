#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        cout << "Cannot insert " << val << ", already in BST" << endl;
    }
    return root;
}

// Utility function to check if a tree is a BST
bool isBSTUtil(Node* node, int min, int max) {
    if (node == nullptr)
        return true;
    if (node->data < min || node->data > max)
        return false;
    return isBSTUtil(node->left, min, node->data - 1) && 
           isBSTUtil(node->right, node->data + 1, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Helper function to check if a tree is balanced and calculate height
bool isBalanced(Node* root, int* height) {
    if (root == nullptr) {
        *height = 0;
        return true;
    }

    int lh = 0, rh = 0;
    if (!isBalanced(root->left, &lh))
        return false;
    if (!isBalanced(root->right, &rh))
        return false;

    *height = max(lh, rh) + 1;

    return abs(lh - rh) <= 1;
}

bool isAVL(Node* root) {
    if (!isBST(root))
        return false;

    int height = 0;
    return isBalanced(root, &height);
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 90);

    inorder(root);
    cout << endl;

    if (isAVL(root))
    {
        cout << "It is an AVL tree" << endl;
    }
    else
    {
        cout << "Not an AVL tree" << endl;
    }

    return 0;
}
