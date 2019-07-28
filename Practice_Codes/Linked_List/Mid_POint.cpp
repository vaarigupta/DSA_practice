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



int midPoint(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head->data;
    }
    node* slow = head;
    node* fast= head->next;

    while( fast!=NULL && fast->next!=NULL)
    {

        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;



}

int main(){


    ///Create a LL of nodes
    node* head = NULL;


    cin>>head;
    cout<<head<<endl<<endl;

    cout<<"Mid point :"<<midPoint(head)<<endl;

return 0;
}

