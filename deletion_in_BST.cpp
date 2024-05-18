#include <iostream>
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
        cout << "Can not insert " << val << ", already in BST" << endl;
    }
    return root;
}

Node *minValueNode(Node *root)
{
    Node *current = root;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node *deleteInBST(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
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
    root = insert(root, 40);
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 60);
    insert(root, 50);
    cout<<"Inorder traversal before deletion"<<endl;
    inorder(root);
    cout << endl;
    deleteInBST(root, 50);
    cout<<"Inorder traversal after deletion"<<endl;

    inorder(root);

    return 0;
}