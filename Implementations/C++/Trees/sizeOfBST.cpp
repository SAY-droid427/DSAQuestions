//Program to calculate the size of the tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int data)
{
    Node *node = new Node();
    node->left = node->right = NULL;
    return node;
}
int sizeOfBST(Node *root)
{
    if (root == NULL)
        return 0;
    return sizeOfBST(root->left) + 1 + sizeOfBST(root->right);
}
int main()
{
    Node *root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);
    root->left->right = createNode(0);
    cout << sizeOfBST(root) << "\n";
}
