#include<bits/stdc++.h>
using namespace std;
//Stacks implement the LIFO implementation
struct Node
{
   int data;
   Node *next;
};
void insert(Node **head,int input_data)
{
    //Node gets inserted at the head
    Node *temp=new Node;
    temp->data=input_data;
    temp->next=NULL;
    if(*head==NULL)
    *head=temp;
    else
    {
        Node *ptr=new Node;
        ptr=*head;
        while(ptr->next!=NULL)
        {
             ptr=ptr->next;
        }
             ptr->next=temp;
            
    }
    
}
void peek(Node *head)
{
    Node *temp=new Node;
    temp=head;
    cout<<head->data<<" ";
}
void printList(Node *head)
{
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
Node* deleteNode(Node *head)
{
    if(head==NULL)
    return NULL;
    Node *temp=new Node;
    temp=head->next;
    head=temp;
    return head;
    
}
int main()
{
     Node *root=NULL;
     int n,d;
     cout<<"Enter the number of items";
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cin>>d;
         insert(&root,d);
     }
     cout<<"The list is:\n";
     printList(root);
     cout<<"The peek element is:";
     peek(root);
     
}