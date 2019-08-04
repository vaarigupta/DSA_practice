/*

KTH ELEMENT FROM LAST IN LINKED LIST
Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

Input Format:
First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.

Constraints:
n < 10^5

Output Format
Output a single line containing the node value at the kth element from last.

Sample Input
1 2 3 4 5 6 -1
3
Sample Output
4

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
node* buildList(node* &head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        //head = insertAtHead(head,d);
        insertAtTail(head,d);
        cin>>d;
    }
    return head;

}
void printList(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
}
int kthElementLast(node* head, int k)
{
    node* fast = head;
    node* slow = head;
    int i=1;
    while(i<k)
    {
        fast = fast->next;
        i++;
    }
    while(fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
    //return fast->data;
}
int main()
{
    node* head = NULL;
    int k;
    head = buildList(head);
    cin>>k;
    printList(head);
    cout<<endl<<kthElementLast(head,k);


    return 0;
}


/*

1 2 3 4 5 6 -1
3
1-->2-->3-->4-->5-->6-->
4

*/
