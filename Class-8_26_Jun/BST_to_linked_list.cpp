#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node * left;
    node* right;
    node(int d)
    {
        data = d;
    }
};
node* BST2LinkedList(node* root)
{
    node* temp =root;
    while(temp!=NULL)
    {
        temp = temp->left;
    }
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left)
    {
        node* temp = root->left;
        temp->right = root;
    }
}

class
int main()
{

    return 0;
}
