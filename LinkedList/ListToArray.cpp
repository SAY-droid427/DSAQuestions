//To convert a linked list into array
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
void convert(Node *head,int arr[])
{
    Node *temp=new Node;
    temp=head;
    int c=0;
    while(temp!=NULL)
    {
        arr[c]=temp->data;        
        temp=temp->next;
       c++;

    }
    for(int i=0;i<c;i++)
    cout<<arr[i]<<" ";

}
int count(Node *root)
{
    int COUNT=0;
    Node *temp=new Node;
    temp=root;
    while(temp!=NULL)
    {
        COUNT++;
        temp=temp->next;
    }
    return COUNT;
}
int main()
{
    Node *root=new Node;
    root=NULL;int n;
    char x;
    
    do
    {
        cout<<"Wanna enter elements\n";
        cin>>x;
        if(x=='y')
        {
         cout<<"Element\n";
        cin>>n;
        insert(&root,n);

        }
       
        
    } while (x=='y');
    int l=count(root);
    int arr[l];
    
    
    convert(root,arr);
    
}