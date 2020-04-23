#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insert(Node **head_ref,int d)
{
    Node *new_node=new Node;
    new_node->data=d;
    new_node->next=*head_ref;
    *head_ref=new_node;

}
void append(Node **head_ref,int d)
{
    Node *new_node=new Node;
    new_node->next=NULL;
    new_node->data=d;
    Node *temp=new Node;
    temp=*head_ref;
    while(temp->next!=NULL)
    {
         temp=temp->next;
    }
    temp->next=new_node;
}
void display(Node *head_ref)
{
    Node *temp=new Node;
    temp=head_ref;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node *root=NULL;
    int n,d;
    cout<<"Enter the no. opf times you want elemenst to be inserted";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Do you want to:\n 1-->Insert the element to top\n2-->Append the element to the end";
        int c;
        cin>>c;
        switch(c)
        {
            case 1:cout<<"Data";
            cin>>d;            
            insert(&root,d);
            break;
            case 2:cout<<"Data";
            cin>>d;           
            append(&root,d);
            break;
        } 
    }
   

    display(root);

}
