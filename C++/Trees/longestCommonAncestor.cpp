//Longest common ancestor
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
    node->right = node->left = NULL;
}
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    return root;
}
int main()
{
    Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    Node *node = LCA(root, 2, 1);
    cout << node->data << " ";
}
