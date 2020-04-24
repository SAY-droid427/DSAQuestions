#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*next;
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
void insertMiddle(Node *head,int k,int insert_data)
{
    Node *temp=new Node;
    temp=head;
    int COUNT=1;
    while(COUNT<k)
    {
        temp=temp->next;
        COUNT++;
    }
    Node *after=temp->next;
   Node* ptr=new Node;
   ptr->next=after;
   ptr->data=insert_data;
   temp->next=ptr;

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
    cout<<"Enter the element you want to insert into the middle\n";
    int n;
    cin>>n;
    int length=count(root);
    int k;
    if(length%2==0)
    k=length/2;
    else
    k=(length+1)/2;
    cout<<"New linked list\n";
    insertMiddle(root,k,n);
    display(root);




}