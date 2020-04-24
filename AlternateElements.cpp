//To form a linked list by putting alternate elements
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insert(Node **head,int input_data)
{
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
void display(Node *head)
{
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void alterList(Node **root1,Node **root2)
{
    Node *r1=*root1;
    Node *r2=*root2;
    
    while(r1!=NULL)
    {
       cout<<r1->data<<" ";
       cout<<r2->data<<" ";
       r1=r1->next;
       r2=r2->next;
    }
    
}

int main()
{
    Node *root1=NULL;
    Node *root2=NULL;
    Node *root=NULL;
    cout<<"Enter the number of elements to be inputted\n";
    int n,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        insert(&root1,d);
    }
    cout<<"\nThe first linked list is:\n";
    display(root1);
    for(int i=0;i<n;i++)
    {
        cin>>d;
        insert(&root2,d);
    }
    cout<<"\nThe second linked list is:\n";
    display(root2);
   
    cout<<"\nThe required list:\n";
     alterList(&root1,&root2);
   

}