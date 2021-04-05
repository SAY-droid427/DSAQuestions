//Remove duplicates from a sorted linked list
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void push(Node **head, int new_data)
{
    Node *temp = new Node();
    temp->data = new_data;
    temp->next = *head;
    *head = temp;
}
void removeDup(Node *head)
{
    Node *temp = new Node();
    temp = head;
    Node *next_next = new Node();
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            next_next = temp->next->next;
            free(temp->next);
            temp->next = next_next;
        }
        else
        {
            temp = temp->next;
        }
    }
}
void printList(Node *head)
{
    Node *temp = new Node();
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;
    push(&head, 8);
    push(&head, 8);
    push(&head, 9);
    cout << "Before deleting:";
    printList(head);
    removeDup(head);
    cout << "\nAfter deleting:";
    printList(head);
}
