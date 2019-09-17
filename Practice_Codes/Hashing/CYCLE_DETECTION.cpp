#include<iostream>
#include<unordered_map>
using namespace std;
class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
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

node* insertAtTail(node* &head, int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return head;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    node * n = new node(d);
    temp->next = n;
    return head;

}
void buildLL(node* &head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        head = insertAtTail(head,d);
        cin>>d;
    }
}
node* getTail(node* head)
{
    while(head->next!=NULL)
    {
        head = head->next;
    }
    return head;
}
void printLL(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}
bool cycleDetect(node* head)
{
    unordered_map<node*, bool> nodesAdd;
    while(head!=NULL)
    {
        if(nodesAdd[head]== true)
        {
            return true;
        }
        nodesAdd[head] = true;
        head = head->next;
    }
    return false;

}
int main()
{
    node* head = NULL;
    buildLL(head);
    printLL(head);
    node* tail = getTail(head);
    tail->next = head->next->next;
   // printLL(head);
   if(cycleDetect(head))
   {
       cout<<"cycle found "<<endl;
   }
   else
   {
       cout<<"No cycle "<<endl;
   }

    return 0;
}
