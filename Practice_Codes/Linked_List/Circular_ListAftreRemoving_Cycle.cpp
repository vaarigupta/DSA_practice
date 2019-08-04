/*
CIRCULAR LINKED LIST
We are given a linked list which contains a cycle. Detect that cycle and break it. Print the linked list after removing the cycle.

Input Format:
The first line contains space separated integers. The integers are such that all the values are distinct but the value start repeating once the cycle gets completed. The list of integers given ends when -1 is input.

Constraints:
n < 10^5 where n is the length of list without the cycle

Output Format
Output single line containing space separated integers representing the list

Sample Input
1 2 3 4 5 2 3 -1
Sample Output
1 2 3 4 5

*/
#include<iostream>
#define ll long long
using namespace std;

class node
{
    public:
    ll data;
    node* next;
    node(ll d)
    {
        data =d;
        next = NULL;
    }
};
void insertAtTail(node* &head, ll d)
{
    node* iterate=head;
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
    while(iterate!=(temp->next))
    {
        if(iterate->data==d)
        {
            return;
        }
        else
        {
            iterate = iterate->next;
        }
    }

    temp->next = new node(d);


}
node* buildList(node *&head)
{
    ll d;
    cin>>d;
    while(d!=-1)
    {
        insertAtTail(head,d);
        cin>>d;
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

ostream& operator<<(ostream &os, node* head)
{
    printList(head);
    return os;
}

int main()
{
    node* head = NULL;
    head = buildList(head);
    printList(head);


    return 0;
}


/*
1
4
1 3 5 7
3
2 4 6
1 2 3 4 5 6 7

*/


