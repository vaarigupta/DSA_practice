/*

PALINDROME
Check if a linked list is a palindrome.( Boolean return type )

Input Format:
Add N space separated elements in the list

Constraints:
None

Output Format
Boolean answer( true or false)

Sample Input
5
1 2 3 6 8
Sample Output
False

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
    n->prev = temp;
    return;
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
bool palindrome(node* head)
{
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    while(head!=temp)
    {
        if(head->data==temp->data)
        {
            head = head->next;
            temp = temp->prev;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    node* head = NULL;
    int n;
    cin>>n;
    head = buildList(head,n);
    //printList(head);
    if(palindrome(head))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }


    return 0;
}


/*

1 2 3 2 1
True

*/


