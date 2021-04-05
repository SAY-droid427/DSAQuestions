//Printing the mirror of a BST
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
void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void mirror(Node *root)
{
    if (root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    Node *temp = new Node();
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
int main()
{
    Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    cout << "Before mirroring:";
    inOrder(root);
    mirror(root);
    cout << "\nAfter mirroring:";
    inOrder(root);
}
