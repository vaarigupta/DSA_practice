#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;
    node( int d)
    {
        data =d;
        left = NULL;
        right = NULL;
    }
};
class LinkedList
{
public:
    node* head;
    node* tail;
};
node* insertInBST(node* &root, int d)
{
    if(root==NULL)
    {
        root = new node(d);
        return root;
    }
    if(d<=root->data)
    {
        root->left = insertInBST(root->left,d);
    }
    else
    {
        root->right = insertInBST(root->right,d);
    }
    return root;
}
void buildBST(node* &root)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        root = insertInBST(root,d);
        cin>>d;
    }
}

void inOrderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}
void levelOrderPrint(node* root)
{
    queue<node*> q;
    q.push(root);
   // q.push(NULL);
    while(!q.empty())
    {
        node* f = q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }

    }
}
void levelOrderPrintEndl(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f = q.front();
        q.pop();
        if(f==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<f->data<<" ";
            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }

    }
}


LinkedList BSTtoLL(node* root)
{
    LinkedList l;
    if(root==NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }
    if(root->left==NULL && root->right==NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        LinkedList leftLL = BSTtoLL(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    if(root->right!=NULL && root->left==NULL)
    {
        LinkedList rightLL = BSTtoLL(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    LinkedList leftLL = BSTtoLL(root->left);
    LinkedList rightLL = BSTtoLL(root->right);
    leftLL.tail->right = root;
    root->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;

}

int main()
{
    node* root =NULL;
    buildBST(root);
    inOrderPrint(root);
    cout<<endl;
    levelOrderPrintEndl(root);
    LinkedList l = BSTtoLL(root);
    node* temp = l.head;
    while(temp!=(l.tail->right))
    {
        cout<<temp->data<<" -->";
        temp = temp->right;
    }

    return 0;
}

/*

5 3 2 4 7 6 10 -1
2 3 4 5 6 7 10
5
3 7
2 4 6 10
2 -->3 -->4 -->5 -->6 -->7 -->10 -->

*/

