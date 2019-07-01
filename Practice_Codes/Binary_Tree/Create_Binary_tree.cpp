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
        left= NULL;
        right = NULL;
    }
};

node* buildTree(node* root)
{
    int d;
    cin>>d;
    if(d== -1)
    {
        return NULL;
    }

    node *n = new node(d);
    n->left = buildTree(n->left);
    n->right = buildTree(n->right);

    return n;
}

void printTree(node* root)
{
    if(root== NULL)
    {
       return;
    }
    cout<<root->data<<" ";


    printTree(root->left);
    printTree(root->right);
}
int main()
{
    node * root = NULL;
    root = buildTree(root);
    printTree(root);
    return 0;
}
