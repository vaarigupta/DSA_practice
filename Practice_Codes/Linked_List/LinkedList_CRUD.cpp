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
        next =NULL;
    }
};

void insertAtHead(node* &head, int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
    return;

}
int len(node* head)
{
    int cnt=0;
    while(head!=NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}
void insertAtTail(node* &head, int d)
{
    if(head ==NULL)
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
    return;
}
void insertInMiddle(node* &head, int d, int p)
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
        int jump = 1;
        node* temp = head;
        while(jump<=(p-1))
        {
            temp = temp->next;
            jump++;
        }
        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;
        return;
    }

}
void deletionAtHead(node *&head)
{
    if(head==NULL)
    {
        return;
    }
    node *temp = head;///stores the address of the head mainly
    head = head->next; /// basically head points to the next node means actual head updated
    delete temp;
    return;
}
void deletionAtTail(node *&head)
{
    node* prev = NULL;
    node* temp = head;
    while(temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
    return;

}
void deletionInMiddle(node *&head, int p)
{
    if(p==0)
    {
        deletionAtHead(head);
        return;
    }
    else if(p>len(head))
    {
        deletionAtTail(head);
        return;
    }
    else
    {
        node* prev = NULL;
        node* temp = head;
        int jmp=1;
        while(jmp<=(p-1))
        {
            prev = temp;
            temp = temp->next;
            jmp++;
        }
        prev->next = temp->next;
        delete temp;
        return;

    }
}
bool searchIterative(node* head, int key)
{
    if(head==NULL)
    {
        return false;
    }
    while(head!=NULL)
    {
        if(head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}
bool searchRecursive(node *head, int key)
{
    if(head==NULL)
    {
        return false;

    }
    if(head->data == key)
    {
        return true;
    }
    return searchRecursive(head->next,key);
}
void printList(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
}
void buildList(node *&head)
{
    int d;
    cout<<"Enter the elements :"<<endl;
    cin>>d;
    while(d!=(-1))
    {
        insertAtTail(head,d);
        cin>>d;
    }
}
istream& operator>>(istream &is , node* &head)
{
    buildList(head);
    return is;
}
ostream& operator<<(ostream &os , node * head)
{
    printList(head);
    return os;
}
int main()
{
  node* head = NULL;
  int d,p;
  cin>>head;
  cout<<head<<endl;
   cout<<"Enter data to add at Head "<<endl;
    cin>>d;
    insertAtHead(head,d);
   cout<<"Insertion at Head "<<endl<<head<<endl;
    cout<<"Enter data to add at Tail"<<endl;
    cin>>d;
    insertAtTail(head,d);
   cout<<"Insertion at Tail "<<endl<<head<<endl;
    cout<<"Enter data and position :"<<endl;
   cin>>d>>p;
   insertInMiddle(head,d,p);
   cout<<"Insertion at Middle"<<endl<<head<<endl;
  cout<<"Enter key to be searched :"<<endl;
  cin>>d;
  if(searchIterative(head,d))
  {
      cout<<"found"<<endl;
  }
  else
  {
      cout<<"Not found "<<endl;
  }
  if(searchRecursive(head,d))
  {
      cout<<"found"<<endl;
  }
  else
  {
      cout<<"Not found "<<endl;
  }

    deletionAtHead(head);
    cout<<"Deletion at Head "<<endl<<head<<endl;
    deletionAtTail(head);
    cout<<"Deletion at tail "<<endl<<head<<endl;
  cout<<"Enter position :"<<endl;
  cin>>p;
  deletionInMiddle(head,p);
  cout<<head<<endl;

    return 0;
}


/*

Enter the elements :
1 2 3 4 5 6 -1
1-->2-->3-->4-->5-->6-->
Enter data to add at Head
0
Insertion at Head
0-->1-->2-->3-->4-->5-->6-->
Enter data to add at Tail
9
Insertion at Tail
0-->1-->2-->3-->4-->5-->6-->9-->
Enter data and position :
70 2
Insertion at Middle
0-->1-->70-->2-->3-->4-->5-->6-->9-->
Enter key to be searched :
70
found
found
Deletion at Head
1-->70-->2-->3-->4-->5-->6-->9-->
Deletion at Head
1-->70-->2-->3-->4-->5-->6-->
Enter position :
4
1-->70-->2-->4-->5-->6-->

*/
