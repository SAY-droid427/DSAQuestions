//To check if an element is present in the BST
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
    return node;
}
int search(Node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    int res1 = search(root->left, key);
    if (res1)
        return res1;
    int res2 = search(root->right, key);
    return res2;
}
int main()
{
    Node *root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(6);
    root->left->left = createNode(3);
    int key;
    cin >> key;
    cout << search(root, key) << "\n";
}
