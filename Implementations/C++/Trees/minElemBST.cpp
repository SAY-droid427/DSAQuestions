//Print the minimum element present in the BST
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
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int minElement(Node *root)
{
    if (root == NULL)
        return 0;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
int main()
{
    Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    cout << minElement(root);
}
