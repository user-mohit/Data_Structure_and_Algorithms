#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isBST(Node *root, Node *min = nullptr, Node *max = nullptr)
{
    if (root == nullptr)
    {
        return true;
    }
    if (min != nullptr && root->data <= min->data)
    {
        return false;
    }
    if (max != nullptr && root->data >= max->data)
    {
        return false;
    }
    bool isLeftValid = isBST(root->left, min, root);
    bool isRightValid = isBST(root->right, root, max);

    return isLeftValid && isRightValid;
}

int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    // inorder(root);

    if (isBST(root, nullptr, nullptr))
    {
        cout << "Valid BST. " << endl;
    }
    else
    {
        cout << "Not valid BST " << endl;
    }

    return 0;
}