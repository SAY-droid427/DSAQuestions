//Make the middle node the head
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insert(Node **head,int input_data)
{
    Node *new_node=new Node;
    new_node->data=input_data;
    new_node->next=NULL;
    if(*head==NULL)
    *head=new_node;
    else
    {
        Node *ptr=new Node;
        ptr=*head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
    
}
int count(Node *head)
{
    int c=0;
    Node *temp=new Node;
    temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
void headChange(Node **head,int k)
{
    Node *temp=new Node;
    temp=*head;
    int COUNT=1;
    while(COUNT<k-1)
    {
        temp=temp->next;
        COUNT++;
    }
    Node *before=temp;
    Node *after=temp->next->next;
    temp->next->next=*head;
    *head=temp->next;
    before->next=after;


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
int main()
{
    Node *root=NULL;
    char x;
    do{
        cout<<"Do you want to enter any more elements?\n";
        cin>>x;
        if(x=='y')
        {
            cout<<"Enter element";
            int d;
            cin>>d;
            insert(&root,d);
        }
        
    }while(x=='y');
    
  
    int length=count(root);
    int k;
    if(length%2==0)
    k=length/2;
    else
    k=(length+1)/2;
    cout<<"New linked list\n";
    headChange(&root,k);
    display(root);


}