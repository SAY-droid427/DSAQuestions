//Tree traversal
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void inOrder(Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
void postOrder(Node *node)
{
    if (node == NULL)
        return;
    postOrder(node->right);
    postOrder(node->left);
    cout << node->data << " ";
}
void preOrder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->right);
    preOrder(node->left);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Inorder traversal:";
    inOrder(root);
    cout << "\nPreorder traversal:";
    preOrder(root);
    cout << "\nPostorder traversal:";
    postOrder(root);
}
/*
OUTPUT:
Inorder traversal:4 2 5 1 3 
Preorder traversal:1 3 2 5 4 
Postorder traversal:3 5 4 2 1
*/
