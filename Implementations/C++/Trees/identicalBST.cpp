//Check whether two binary search trees are identical
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
Node *createBST(int a[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = createNode(a[mid]);
    root->left = createBST(a, start, mid - 1);
    root->right = createBST(a, mid + 1, end);
    return root;
}
int identical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    else if (root1 != NULL && root2 != NULL)
    {
        return (root1->data == root2->data && identical(root1->left, root2->left) && identical(root1->right, root2->right));
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    Node *root1 = createBST(a, 0, n - 1);
    Node *root2 = createBST(b, 0, m - 1);
    if (identical(root1, root2))
        cout << "Identical\n";
    else
        cout << "Not identical\n";
}
