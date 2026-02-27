// preorder
// post order
// inorder
#include <bits/stdc++.h>
#include "../tree_node.h"
using namespace std;

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