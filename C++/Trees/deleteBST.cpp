//Program to delete a binary search tree
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
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void deleteBST(Node *root)
{
    if (root == NULL)
        return;
    deleteBST(root->left);
    deleteBST(root->right);
    cout << "Deleting " << root->data << "\n";
    delete root;
}
int main()
{
    Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    deleteBST(root);
}
