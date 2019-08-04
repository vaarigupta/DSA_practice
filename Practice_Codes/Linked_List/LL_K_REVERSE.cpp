/*

LL - K REVERSE
Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format:
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints:
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5
Sample Output
1 4 9 3 8 7 5 6 2

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
node* getLastNode(node*head)
{
    while(head->next!=NULL)
    {
        head = head->next;
    }
    return head;
}

node*& reverseList(node* &head)
{
    node* prev =NULL;
    node* temp = head;
    node* curr = head;
    while(curr!=NULL)
    {
        temp = temp->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;

}
void reverseLL(node*&head, int n, int k)
{

    int j=1;
    node* temp = head;
    node* aglaNode = head->next;
    node* smallHead = head;
    for(int i=1;i<=(n/k);i++)
    {
        j=1;
        while(j<k)
        {
            temp = temp->next;
            aglaNode = aglaNode->next;
            j++;

        }

        temp->next = NULL;
        temp = reverseList(smallHead);
        if(i==1)
        {
            head = temp;
        }
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = aglaNode;
        smallHead = aglaNode;
    }


}
//node* getLastNode(node* head)
//{
//    while(head->next!=NULL)
//    {
//        head = head->next;
//    }
//    return head;
//}
node* reverseLL1(node* &head, int n , int k)
{
     node*smallHead = head;
    node* temp =head;
    node* aglaNode = head->next;
    if(n==0)
    {
        return head;
    }
    if((n/k)!=0)
    {
         while(temp->next!=NULL)
        {
            temp = temp->next;
            aglaNode = aglaNode->next;
        }
            temp->next = NULL;
            temp = reverseList(smallHead);
            temp->next = reverseLL1(aglaNode,n/k,k);
            head = temp;

    }

}
int main()
{
    node* head = NULL;
    int n,k;
    cin>>n>>k;
    head = buildList(head,n);
    head = reverseLL1(head,n,k);
    printList(head);


    return 0;
}


/*



*/




