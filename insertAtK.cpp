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
void insertAtK(Node **head,int k,Node *root)
{
    int count=1;
    Node *temp=new Node;
    temp=*head;
    while(count<k)
    {
        temp=temp->next;
        count++;
    }

    Node *after=temp->next;
    temp->next=root;
    Node*ptr=new Node;
    ptr=root;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=after;



}

int main()
{
    Node *root1=NULL;
    cout<<"Enter the length of the linked list you want to insert into";
    int n,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Element";
        cin>>d;
        insert(&root1,d);

    }
    Node *root2=NULL;
    cout<<"Enter the length of the linked list you want to insert";
    int N,D;
    cin>>N;
    for(int j=0;j<N;j++)
    {
        cout<<"Element";
        cin>>D;
        insert(&root2,D);
    }

    //Displaying the original linked list
    cout<<"The original linked list\n";
    display(root1);
    cout<<"\nThe second linked list\n";
    display(root2);
    cout<<"\nEnter the position you want to enter the second linked list into";
    int k;
    cin>>k;
    insertAtK(&root1,k,root2);
    cout<<"New linked list\n";
    display(root1);


}