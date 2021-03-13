//Insertion in a binary tree in level order
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};
Node *insert(Node *root, int data)
{
    Node *temp = root;
    //If the tree is empty then we assign the root to the new data
    if (temp == NULL)
    {
        root = new Node(data);
        return root;
    }
    else
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            else
            {
                temp->left = new Node(data);
                return root;
            }
            if (temp->right != NULL)
                q.push(temp->right);
            else
            {
                temp->right = new Node(data);
                return root;
            }
        }
    }
}
void inOrder(Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    cout << "Before insertion:";
    inOrder(root);
    insert(root, 5);
    cout << "\nAfter insertion:";
    inOrder(root);
}
