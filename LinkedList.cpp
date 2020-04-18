//Linked list implementation
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* link;
};
void insert(Node **head_ref,int in)
{
    Node *new_node=new Node;
    new_node->data=in;
    new_node->link=*head_ref;
    *head_ref=new_node;
}
void printList(Node *root)
{
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->link;
    }
}
void checkPresent(Node *root,int k)
{
    int flag=1;
    while(root!=NULL)
    {
        if(root->data==k)
        {
            flag=0;
            cout<<"Present\n";
            break;
        }
        root=root->link;
        
    }
    if(flag==0)
    cout<<"Not present\n";

}

int main()
{
    Node *first=new Node;
    Node *second=new Node;
    Node *third=new Node;
    first->data=1;
    second->data=2;
    third->data=3;
    first->link=second;
    second->link=third;
    third->link=NULL;
    int n;
    cin>>n;
    insert(&first,n);
    printList(first);
    int key;
    cin>>key;
    checkPresent(first,key);

}
