#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int input_data)
    {
        this->data=input_data;
        right=NULL;
        left=NULL;
    }
};
struct Node* BST(Node *root,int a[],int n,int i)
{
    if(i<n)
    {
        Node *temp=new Node(a[i]);
        root=temp;
        root->left=BST(root->left,a,n,2*i+1);
        root->right=BST(root->right,a,n,2*i+2);
    }
    return root;
}
void preOrder(Node *temp)
{
    if(temp==NULL)
    return;
    cout<<temp->data<<" ";
    preOrder(temp->left);
    preOrder(temp->right);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    Node *root=BST(root,a,n,0);
    preOrder(root);
    return 0;

}
