//Remove duplicate nodes in a singly linked list
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
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
void removeDuplicate(Node **head)
{
  
     Node* curNode = *head;
    while(curNode->next){
        if(curNode->data == curNode->next->data){
            curNode->next = curNode->next->next;
        }
        else
        {
            curNode = curNode->next;
        }
    }

}

int main()
{
    Node *root=NULL;
    int n;
    cout<<"Enter the number of elements in thelinked list\n";
    cin>>n;
    int i,a[n];
    cout<<"\nEnter the elements in ascending order\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];        
    }
    //Inserting the elements

    for(int i=0;i<n;i++)
    {
        insert(&root,a[i]);
    }
    cout<<"\nThe linked list:\n";
    display(root);
    removeDuplicate(&root);
    cout<<"\nThe modified list:\n";
    display(root);



}