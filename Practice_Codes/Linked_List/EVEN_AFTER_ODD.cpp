/*

EVEN-AFTER-ODD
Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

Input Format:
Enter N space separated Elements

Constraints:
None

Output Format
Linked list with all the odd numbers before even numbers

Sample Input
5
1 2 2 2 1
Sample Output
1 1 2 2 2

*/
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        data =d;
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
    temp->next = new node(d);
}
node* buildList(node* &head, int n)
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
node* evenAfterOdd(node*head)
{
    if(head==NULL)
    {
        return head;
    }
    node* temp = head;
    node* odd = head;
    int a[100];
    int i=0;
    while(temp!=NULL)
    {
        if(temp->data&1)
        {
            odd->data = temp->data;
            odd = odd->next;
        }
        else
        {
          a[i] = temp->data;
          i++;
        }
        temp = temp->next;
    }
    i=0;
    while(odd!=NULL)
    {
        odd->data = a[i];
        i++;
        odd = odd->next;
    }
    return head;
}
int main()
{
    node* head = NULL;
    int n;
    cin>>n;
    head = buildList(head,n);
    printList(head);
    head = evenAfterOdd(head);
    cout<<endl;
    printList(head);


    return 0;
}


/*

8
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7 8
1 3 5 7 2 4 6 8

*/

