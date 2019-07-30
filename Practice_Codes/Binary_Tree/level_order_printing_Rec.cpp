#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node* root)
{
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }
    root = new node(d);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}
///Pre Order Print
void PreOrderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";///root
    PreOrderPrint(root->left);///left
    PreOrderPrint(root->right);///right
}
///In Order Print
void InOrderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }
    InOrderPrint(root->left);
    cout<<root->data<<" ";
    InOrderPrint(root->right);
}
///Post Order Print
void PostOrderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }

    PostOrderPrint(root->left);
    PostOrderPrint(root->right);
    cout<<root->data<<" ";
}
void levelOrderPrint(node* root)
{
    queue<node*> q;
    q.push(root);
    cout<<q.front()->data<<" ";
    while(!q.empty())
    {
        node* f = q.front();
        node* l = f->left;
        node* r = f->right;
        if(l!=NULL)
        {
            cout<<l->data<<" ";
            q.push(l);


        }
        if(r!=NULL)
        {
            cout<<r->data<<" ";
            q.push(r);
        }
        q.pop();
    }

}
void levelOrderPrint1(node* root)
{
    queue<node*> q;
    q.push(root);
    cout<<q.front()->data<<" ";
    while(!q.empty())
    {
        node* f = q.front();
        q.push(NULL);
        node* l = f->left;
        node* r = f->right;
        if(f!=NULL)
        {
        if(l!=NULL)
        {
            cout<<l->data<<" ";
            q.push(l);


        }
        if(r!=NULL)
        {
            cout<<r->data<<" ";
            q.push(r);
        }
        q.pop();
        }

    }

}
int height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l,r);
}
void printKthLevel(node* root , int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}
void printAllLevel(node* root)
{
    int h = height(root);
    for(int i=1;i<=h;i++)
    {
        printKthLevel(root,i);
        cout<<endl;
    }
}
int main()
{

    node* root = NULL;
    root = buildTree(root);
    cout<<"Level order Print :"<<endl;
    levelOrderPrint(root);
    cout<<endl<<"Height of tree : "<<height(root)<<endl;
    printKthLevel(root,3);
    cout<<endl;
    printAllLevel(root);
    return 0;
}

/*

8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Level order Print :
8 10 3 1 6 14 9 7 13
Height of tree : 4
1 6 14
8
10 3
1 6 14
9 7 13
*/



