//Find the minimum element in the linked list
#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node *next;
   Node *link;
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
        ptr=ptr->next;
        ptr->next=temp;
    }
    
}
void display(Node *head)
{
    Node *temp=new Node;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void findMin(Node *head)
{
    Node *temp=new Node;
    temp=head;
    int COUNT=1,pos;
    int min=INT_MAX;
    while(temp!=NULL)
    {
        if(min>temp->data)
        {
        
          min=temp->data;
          pos=COUNT;
        }
          COUNT++;   
        
        temp=temp->next;
       

    }
    cout<<"Minimum element is "<<min<<" present at position "<<pos<<"\n";
}

int main()
{
    Node *root=NULL;
    int n,d;
    cout<<"Enter the number of elements to be entered\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Element";
        cin>>d;
        insert(&root,d);
    }
    findMin(root);



}