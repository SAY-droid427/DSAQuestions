//Code to print the count of leaf nodes in a tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
};
Node *createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int countLeafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL || root->right == NULL)
        return 1;
    else
        return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main()
{
    Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    cout << "No. of leaf nodes=" << countLeafNodes(root);
}
