#ifndef TREE_NODE_H
#define TREE_NODE_H

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

#endif // TREE_NODE_H
