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
//void buildBT(node* root, int d)
//{
//    if(root==NULL)
//    {
//        root = new node(d);
//    }
//    root->left = buildBT(root->left,d);
//    root->right = buildBST(root->right,d);
//
//}
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
bool checkBST(node* root, int minV= INT_MIN ,int maxV = INT_MAX)
{

    if(root==NULL)
    {
        return true;
    }
    if(minV<=root->data && root->data<=maxV && checkBST(root->left, minV,root->data) && checkBST(root->right, root->data,maxV))
    {

        return true;
    }
    return false;

}

node* minVal(node * root)
{
    if(root==NULL)
    {
        return root;
    }
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}
node* righMinVal(node* root)
{
    if(root==NULL || root->right==NULL)
    {
        return root;
    }
    root = root->right;
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}
node* BSTtoLL(node* & root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL) )
    {
        return root;
    }

}
int main()
{
    node* root =NULL;
    buildBST(root);
    inOrderPrint(root);
    cout<<endl;
    levelOrderPrintEndl(root);
    if(checkBST(root))
    {
        cout<<"Yes BST"<<endl;
    }
    else
    {
        cout<<"Not a BST"<<endl;
    }
    cout<<"MIn Value from whole BST "<<minVal(root)->data<<endl;
     cout<<"MIn Value from right "<<righMinVal(root)->data<<endl;
    return 0;
}

/*

5 3 2 4 7 6 10
-1
2 3 4 5 6 7 10
5
3 7
2 4 6 10

*/
