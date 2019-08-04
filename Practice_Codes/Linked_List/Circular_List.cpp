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

void insertion(node* &head, int d)
{
    node* n = new node(d);
    n->next = head;
    node* temp = head;/// to traverse the linked list and find its tail
    if(head!=NULL)
    {
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        n->next = n;
    }
    head = n;
}

void printList(node* head)
{
      node* temp = head;
  if(head!=NULL)
  {
      while(temp->next!=head)
      {
          cout<<temp->data<<"->";
          temp = temp->next;
      }
  }
  cout<<temp->data<<endl;
}
void buildList(node* &head)
{
    int d;
    cout<<"Enter numbers "<<endl;
    cin>>d;
    while(d!=(-1))
    {
        insertion(head,d);
        cin>>d;
    }
}
node *getNode(node* &head, int d)
{
    node *temp = head;
   while(temp!=NULL && temp->next!=head)
   {
       if(temp->data==d)
       {
           return temp;
       }
       temp = temp->next;
   }
     if(temp->data==d) return temp;
    else return NULL;

}
void deletion(node*&head, int d)
{
    node* delNode = getNode(head,d);

    if(delNode==NULL)
    {
        cout<<"Node is not present "<<endl;
        return;
    }
    if( delNode== head)
    {
        head = delNode->next;
    }
    node* temp = head;
    while(temp->next!=delNode)
        {
            temp = temp->next;
        }
        temp->next = delNode->next;
        delete delNode;

}
istream & operator>>(istream &is , node* &head)
{
    buildList(head);
    return is;


}
ostream & operator<<(ostream &os, node* head)
{
    printList(head);
    return os;
}

int main(){

    ///Create a LL of nodes
    node* head = NULL;
    int d;
    cin>>head;
    cout<<head;
    cout<<"enter the node to be deleted :"<<endl;
    cin>>d;
    deletion(head,d);
    cout<<head;
      cout<<"enter the node to be deleted :"<<endl;
    cin>>d;
    deletion(head,d);
    cout<<head;
      cout<<"enter the node to be deleted :"<<endl;
    cin>>d;
    deletion(head,d);
    cout<<head;
return 0;
}

