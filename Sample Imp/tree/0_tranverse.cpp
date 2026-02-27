// preorder
// post order
// inorder
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = this->right = NULL;
    }
};

void printInorder(Node *root)
{
    if (root == NULL)
        return;

    // left
    printInorder(root->left);
    // node
    cout << root->data << " ";
    // right
    printInorder(root->right);
}

void printPreorder(Node *root)
{
    if (root == NULL)
        return;

    // node
    cout << root->data << " ";
    // left
    printPreorder(root->left);
    // right
    printPreorder(root->right);
}

void printPostorder(Node *root)
{
    if (root == NULL)
        return;

    // left
    printPostorder(root->left);
    // right
    printPostorder(root->right);
    // node
    cout << root->data << " ";
}

int main()
{
    cout << "Enter the number of nodes: ";
    return 0;
}