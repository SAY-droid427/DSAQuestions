//Depth of the tree
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int input_data)
    {
        this->data;
         right=NULL;
         left=NULL;
    }
};
struct Node* binTree(Node *root,int a[],int i,int n)
{
    if(i<n)
    {
        Node *temp=new Node(a[i]);
        root=temp;
        root->left=binTree(root->left,a,2*i+1,n);
        root->right=binTree(root->right,a,2*i+2,n);
    }
    return root;
}
int depth(Node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        int ldep=depth(root->left);
        int rdep=depth(root->right);
        if(ldep>rdep)
        return (ldep+1);
        else
        return (rdep+1);

    }
    
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  Node *root=binTree(root,a,0,n);
  cout<<depth(root)<<"\n";
  return 0;     
}
