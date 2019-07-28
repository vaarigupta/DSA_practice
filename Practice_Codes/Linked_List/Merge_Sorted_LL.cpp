#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node*&head, int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node * n = new node(d);
    n->next = head;
    head = n;
}

void insertAtTail(node * &head, int d)
{
    if(head==NULL)
    {
        insertAtHead(head,d);
        return;
    }
    node * temp=head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(d);

}

void buildList(node *&head)
{
    int d;
    cout<<"Enter the Elements :"<<endl;
    cin>>d;
    while(d!=-1)
    {
        insertAtTail(head,d);
        cin>>d;
    }
}
void printList(node *head)
{
    if(head==NULL)
    {
        return;
    }
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    return;
}
istream & operator>>(istream &is , node * &head)
{
    buildList(head);
    return is;
}
ostream & operator<<(ostream &os , node* head)
{
    printList(head);
    return os;
}

node* merge2LL(node* head, node* head2)
{
    if(head==NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head;
    }
   node *newHead ;
   if(head->data <= head2->data)
   {
       newHead = head;
       newHead->next = merge2LL(head->next, head2);
   }
   else
   {
       newHead = head2;
       newHead->next = merge2LL(head, head2->next);
   }
   return newHead;
}
int main(){


    ///Create a LL of nodes
    node* head = NULL;
    node* head2 = NULL;
    cin>>head>>head2;
    cout<<"Linked list :"<<endl<<head<<endl<<head2<<endl;
    head = merge2LL(head, head2);
    cout<<head<<endl;

return 0;
}

