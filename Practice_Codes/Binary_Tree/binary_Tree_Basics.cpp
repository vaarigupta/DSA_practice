#include<iostream>
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
int main()
{

    node* root = NULL;
    root = buildTree(root);
    cout<<"Pre order Print :"<<endl;
    PreOrderPrint(root);
    cout<<endl;
    cout<<"In order Print :"<<endl;
    InOrderPrint(root);
    cout<<endl;
    cout<<"Post order Print :"<<endl;
    PostOrderPrint(root);
    return 0;
}

/*

8 10 1 -1 -1 12 -1 -1 13 -1 -1

8 10 1 -1 -1 12 -1 -1 13 -1 -1
Pre order Print :
8 10 1 12 13
In order Print :
1 10 12 8 13
Post order Print :
1 12 10 13 8



---------------------------------

8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Pre order Print :
8 10 1 6 9 7 3 14 13
In order Print :
1 10 9 6 7 8 3 13 14
Post order Print :
1 9 7 6 10 13 14 3 8
*/
