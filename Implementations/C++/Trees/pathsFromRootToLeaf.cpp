//Print all paths from the root to leaves
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
void printArray(int path[], int n)
{
    for (int i = 0; i < n; i++)
        cout << path[i] << " ";
    cout << "\n";
}
void printPathRecur(Node *root, int path[], int pathLen)
{
    if (root == NULL)
        return;
    path[pathLen] = root->data;
    pathLen++;
    if (root->left == NULL && root->right == NULL)
        printArray(path, pathLen);
    else
    {
        printPathRecur(root->left, path, pathLen);
        printPathRecur(root->right, path, pathLen);
    }
}
void printPaths(Node *root)
{
    int path[1000];
    printPathRecur(root, path, 0);
}
int main()
{
    Node *root = createNode(4);
    root->left = createNode(3);
    root->right = createNode(5);
    root->left->left = createNode(2);
    printPaths(root);
}
