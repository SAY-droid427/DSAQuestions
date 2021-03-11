//Detecting a loop in a linked list
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int marker;
    Node *next;
};
void push(Node **head, int new_data)
{
    Node *temp = new Node();
    temp->data = new_data;
    temp->next = *head;
    temp->marker = 0;
    *head = temp;
}
int detectCycle(Node *head)
{
    Node *temp = new Node();
    temp = head;
    while (temp != NULL)
    {
        if (temp->marker == 0)
            temp->marker = 1;
        else if (temp->marker == 1)
            return 1;
        temp = temp->next;
    }
    return 0;
}
int main()
{
    Node *head = new Node();
    head->data = 1;
    head->marker = 0;
    Node *first = new Node();
    first->data = 5;
    head->marker = 0;
    Node *second = new Node();
    first->data = 7;
    head->marker = 0;
    Node *third = new Node();
    head->marker = 0;
    third->next = first;
    head->next = first;
    first->next = second;
    second->next = third;
    if (detectCycle(head))
        cout << "Present\n";
    else
        cout << "Not present\n";
}
