//To print the maximum and minimum element in a sorted array by using a converting it to a binary tree
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
struct Node *binTree(Node *root,int a[],int i,int n)
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
int minElement(Node *root)
{
    if(root==NULL)
    return INT_MAX;
    int res=root->data;
    int lres=minElement(root->left);
    int rres=minElement(root->right);
    if(lres<res)
    res=lres;
    if(rres<res)
    res=rres;
    return res;
}
int maxElement(Node *root)
{
    if(root==NULL)
    return INT_MIN;
    int res=root->data;
    int lres=maxElement(root->left);
    int rres=maxElement(root->right);
    if(lres>res)
    res=lres;
    if(rres>res)
    res=rres;
    return res;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    Node *root=binTree(root,a,0,n);
    cout<<"Minimum element"<<minElement(root)<<"\n";
    cout<<"Maximum element"<<maxElement(root)<<"\n";
    return 0;

}
