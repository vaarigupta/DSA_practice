/*

MERGE SORTED LINKED LISTS
Given 2 sorted linked lists , Merge the two given sorted linked list and print the final LinkedList.

Input Format:
First Line contains T the number of test cases. For each test case : Line 1 : N1 the size of list 1 Line 2 : N1 elements for list 1 Line 3 : N2 the size of list 2 Line 4 : N1 elements for list 2

Constraints:
1 <= T <= 1000 0<= N1, N2 <= 10^6 -10^7 <= Ai <= 10^7

Output Format
T lines of merged output

Sample Input
1
4
1 3 5 7
3
2 4 6
Sample Output
1 2 3 4 5 6 7

*/
#include<iostream>
#define ll long long
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(ll d)
    {
        data =d;
        next = NULL;
    }
};
node* insertAtHead(node* &head, ll d)
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
void insertAtTail(node* &head, ll d)
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
node* buildList(node* &head, ll n)
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

ostream& operator<<(ostream &os, node* head)
{
    printList(head);
    return os;
}
node* Merge(node*head1, node*head2, node*mergeHead)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    if(head1->data<=head2->data)
    {
        mergeHead = head1;
        mergeHead->next = Merge(head1->next, head2, mergeHead);
    }
    else
    {
        mergeHead = head2;
        mergeHead->next = Merge(head1, head2->next,mergeHead);
    }
    return mergeHead;
}
int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* newHead = NULL;
    ll t,n1,n2;
    cin>>t;
    while(t--)
    {
        cin>>n1;
        head1 = buildList(head1,n1);
        cin>>n2;
        head2 = buildList(head2,n2);
        newHead = Merge(head1,head2, newHead);
        cout<<newHead;
    }


    return 0;
}


/*
1
4
1 3 5 7
3
2 4 6
1 2 3 4 5 6 7

*/

