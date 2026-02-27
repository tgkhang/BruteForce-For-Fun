// The code creates a balanced BST.

#include <bits/stdc++.h>

#include "../tree_node.h"

using namespace std;

// Directly build BST from sorted array (alternative approach)
Node* sortedArrayToBST(vector<int>& arr, int start, int end) {
  if (start > end) return nullptr;

  int mid = start + (end - start) / 2;
  Node* root = new Node(arr[mid]);

  root->left = sortedArrayToBST(arr, start, mid - 1);
  root->right = sortedArrayToBST(arr, mid + 1, end);

  return root;
}

int main() {
  // Method 1: Build BST directly from sorted array
  // this bst is balanced, height = log(n)
  vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7};
  Node* root1 = sortedArrayToBST(sortedArr, 0, sortedArr.size() - 1);

  return 0;
}