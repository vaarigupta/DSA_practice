#include<iostream>
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
void insertAtHead(node *&head, int d)
{
    if(head==NULL)
    {
        node*n = new node(d);
        head = n;
        return;
    }
    node * n = new node(d);
    n->next = head;
    head = n;
    return;

}
void insertAtTail(node* &head, int d)
{

   if(head==NULL )
   {
       insertAtHead(head,d);
       return;
   }
    node* temp = head;
   while(temp->next!=NULL)
   {
       temp = temp->next;
   }
   node* n = new node(d);
   temp->next = n;
   return;
}
int len(node* head)
{
    int cnt =0;
    while(head!=NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
void insertAtMiddle(node* &head,int d, int p)
{

    if(head==NULL || p==0)
    {
        insertAtHead(head,d);
        return;
    }
    else if(p>len(head))
    {
        insertAtTail(head,d);
        return;
    }
    else
    {
    int i=1;
    node* temp = head;
      while(i<=(p-1))
        {
           temp = temp->next;
           i++;
        }
    node *n = new node(d);
    n->next = temp->next;
    temp->next = n;
    return;

    }

}
void buildList(node *&head)
{
    int d;
    cout<<"Enter the numbers :"<<endl;
    cin>>d;
    while(d!=(-1))
    {
        insertAtTail(head,d);
        cin>>d;
    }
    return;
}
void printList(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    return;
}
istream& operator>>(istream &is, node* &head)
{
    buildList(head);
    return is;
}
ostream& operator<<(ostream &os, node*head)
{
    printList(head);
    return os;
}
int main()
{
    node* head= NULL;
    int d,p;
    cin>>head;
    cout<<head<<endl;
    cout<<"Enter the data and position"<<endl;
    cin>>d>>p;
    insertAtMiddle(head,d,p);
    cout<<head;
    cout<<endl<<"Enter the data at tail"<<endl;
    cin>>d;
    insertAtTail(head,d);
    cout<<head;
    cout<<endl<<"Enter the data at head"<<endl;
    cin>>d;
    insertAtHead(head,d);
    cout<<head;
    cout<<endl<<"Length of Linked List : "<<len(head)<<endl;
    return 0;

}

/*

Enter the numbers :
1 2 3 4 5 6 -1
1-->2-->3-->4-->5-->6-->
Enter the data and position
9 2
1-->2-->9-->3-->4-->5-->6-->
Enter the data at tail
20
1-->2-->9-->3-->4-->5-->6-->20-->
Enter the data at head
89
89-->1-->2-->9-->3-->4-->5-->6-->20-->
Length of Linked List : 9

*/
