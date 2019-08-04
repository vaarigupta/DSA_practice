/*

SORT LINKED LIST USING INSERTION SORT
Given a linked list with n nodes. Sort the linked list using insertion sort.

Input Format:
First line contains the number of nodes in the linked list n and then next line contains n space separated integers representing the node values of the linked list.

Constraints:
n < 30

Output Format
Print the linked list after sorting it using insertion sort.

Sample Input
5
2 3 4 1 5
Sample Output
1 2 3 4 5

*/
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* prev;
    node* next;
    node(int d)
    {
        data =d;
        prev = NULL;
        next = NULL;
    }
};
node* insertAtHead(node* &head, int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return head;
    }
    node* n = new node(d);
    n->next = head;
    head->prev = n;
    head = n;
    return head;
}
void insertAtTail(node* &head, int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    node* n = new node(d);
    temp->next = n;
    n->prev= temp;
    return;

}
node* buildList(node*&head, int n)
{
    int d;
    while(n--)
    {
        cin>>d;
        insertAtTail(head,d);
    }
    return head;
}
void printList(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}
void insertionSort(node* &head)
{
    node* temp = head->next;
    node* backptr = NULL;
    int no = 0;
    while(temp!=NULL)
    {
        no = temp->data;
        for(backptr = temp->prev; backptr!=NULL && backptr->data >no;backptr= backptr->prev)
        {
           backptr->next->data = backptr->data;
        }
        backptr->next->data = no;
        temp = temp->next;
    }
}
int main()
{
    node* head = NULL;
    int n;
    cin>>n;
    head = buildList(head,n);
    insertionSort(head);
    printList(head);


    return 0;
}


/*

1 2 3 2 1
True

*/


