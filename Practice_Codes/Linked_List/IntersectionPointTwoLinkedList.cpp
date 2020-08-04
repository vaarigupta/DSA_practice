/*

INTERSECTION POINT TWO LINKED LISTS
There are two linked lists. Due to some programming error, the end node of one of the linked list got linked into the second list,
forming an inverted Y shaped list. Now it's your job to find the point(Node) at which the two linked lists are intersecting.

Input Format:
The first line of input is the size(N1) of the first linked list, followed by its content(Xi). The third line of input is the size(N2) of the second linked list, followed by its content( Yi ).

Constraints:
1<=N, N2<=100 0<=Xi, Yi<=100

Output Format
A single integer denoting the intersection point of two linked lists. If the linked lists are not intersecting at any point then print -1.

Sample Input
5
10 20 30 40 50
4
15 25 40 50
Sample Output
40

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
/// my solution
int intersectionPoint(node*head1 , node* head2)
{
    node* tail1 = getLastNode(head1);
    node* tail2 = getLastNode(head2);
    if(tail1->data!=tail2->data)
    {
        return -1;
    }
    while(tail1->data==tail2->data && tail1!=NULL && tail2!=NULL)
    {
        tail1 = tail1->prev;
        tail2 = tail2->prev;
    }
    return tail1->next->data;

}
/// sir solution
int intersectionPoint1(node*head1 , node* head2, int n1, int n2)
{

   int l1,l2;
   node* temp1 = NULL;
   node* temp2 = NULL;
   if(n1>=n2)
   {
       l1=n1;
       temp1 = head1;
       l2 = n2;
       temp2 = head2;
   }
   else
   {
       l1 = n2;
       temp1 = head2;
       l2 = n1;
       temp2 = head1;
   }
   int diff = abs(l1-l2);
   while(diff--)
   {
       temp1 = temp1->next;

   }
   while(temp1->data!=temp2->data && temp1!=NULL && temp2!=NULL)
   {
       temp1 = temp1->next;
       temp2 = temp2->next;
   }
   if(temp1==NULL || temp2==NULL)
   {
       return -1;
   }
   return temp1->data;


}
int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    int n1,n2;
    cin>>n1;
    head1 = buildList(head1,n1);
    cin>>n2;
    head2 = buildList(head2,n2);
    cout<<intersectionPoint1(head1,head2,n1,n2);

    return 0;
}


/*
4
15 25 40 50
5
10 20 30 40 50
40


*/

//
//hey @LPLC0114, your approach is not correct.
//here is correct approach to solve these question.
//Traverse the bigger list from the first node till d (where d= absolute differece of length of two LL)nodes so that from here onwards both the lists have equal no of nodes.
//Then we can traverse both the lists in parallel till we come across a common node. This common node will be intersection point.

