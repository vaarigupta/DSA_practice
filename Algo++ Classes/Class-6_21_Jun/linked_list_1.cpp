#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

//    node(int d)
//    {
//        data =d;
//        next = NULL;
//    }
//   '

    node(int d):data(d),next(NULL){}
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
        cout<<"Deleting :"<<data;
    }

};

///* in head is the data type - node*
/// but we pass here head by reference bcz it will not update itself in case of pass by value

void insertAtHead(node* &head, int d)
{
    if(head == NULL)
    {
        head = new node(d);
        return;
    }
    node * n = new node(d);
    n->next = head;
    head = n;
}

void print(node * head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ->";
        head = head->next;
    }
}

void createList(node *&head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        insertAtHead(head,d);
        cin>>d;
    }
}
void insertInMiddle(node *&head,int d, int p)
{
    int temp =0;
    node* temphead = head;
    if(p==0)
    {
        insertAtHead(head,d);
    }
    while(temp!= (p-1))
    {
        temphead = temphead->next;
        temp++;
    }
    if(temp==(p-1))
    {
        node *n = new node(d);
        n->next = temphead->next;
        temphead->next= n;

    }

}

void deleteInMiddle(node*&head, int p)
{
    int jump =1;
    node *temp = head;
    node * prev = NULL;
    if(p==0)
    {
        node * temp = head->next;
        head->next = NULL;
        delete head;
        head = temp;

    }
    while(jump!=(p-1))
    {
        prev = temp;
        temp = temp->next;
        jump++;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;

}
istream & operator>> (istream & is , node* &head)
{
   createList(head);
    return is;
}

ostream &operator <<(ostream &os , node * head)
{
    print(head);
    return os;
}

int searchKey(node*&head , int key)
{
    node* temp = head;
    int p=0;
    while((temp!=NULL) && (temp->data!= key) )
    {
        temp = temp->next;
        p++;
    }
    if(temp==NULL)
    {
        return -1;
    }

   return p;

}

//node* reverse_rec(node* head)
//{
//
//}
//node* reverse_it
int main()
{
    node *head = NULL;
    int d,p,key;
    cin>>head;
    cout<<head;
    cout<<"enter the data and position : "<<endl;
    cin>>d>>p;
    insertInMiddle(head,d,p);
    cout<<head;
//    cout<<"enter the  position : "<<endl;
//    cin>>p;
//    deleteInMiddle(head,p);
//    cout<<head;
     cout<<"Enter key :"<<endl;
     cin>>key;
     cout<<key<<"found at"<<searchKey(head,key);
    ///print(head);
    return 0;
}
