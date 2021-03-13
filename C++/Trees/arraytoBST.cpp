//Conversion from array to a binary search tree
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *new_node(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}
Node *createBST(int a[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = new_node(a[mid]);
    root->left = createBST(a, start, mid - 1);
    root->right = createBST(a, mid + 1, end);
    return root;
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    inOrder(root->left);
    inOrder(root->right);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node *root = createBST(a, 0, n - 1);
    inOrder(root);
}
