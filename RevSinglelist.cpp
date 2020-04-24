//To print the reverse of the singly linked list 
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insert(Node **head,int input_data)
{
    Node*temp=new Node;
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
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void revList(Node *head)
{
    Node *temp=head;
    stack<int> s;
    while(temp!=NULL)
    {
        s.push(temp->data);        
        temp=temp->next;
    }
    cout<<"\nThe reverse form is:\n";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}
int main()
{
    Node *root=NULL;
    cout<<"Enter the number of elements to be entered:";
    int n,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        insert(&root,d);
    }
    cout<<"\nThe  list:\n";
    display(root);
    revList(root);

}