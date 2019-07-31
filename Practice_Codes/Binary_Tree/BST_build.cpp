#include<iostream>
#include<queue>
#include<cmath>
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
node* insertInBST(node* root, int d)
{
    if(root==NULL)
    {
        root = new node(d);
        return root;
    }
    if(d<= root->data)
    {
        root->left = insertInBST(root->left,d);
    }
    else
    {
        root->right = insertInBST(root->right,d);
    }
}
node* buildBST(node* root)
{
    int d;
    cin>>d;
    while(d!= -1)
    {
       root = insertInBST(root,d);
       cin>>d;
    }
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
    q.push(NULL);
    while(!q.empty())
    {
        node *f = q.front();
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
        if(f->left )
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

bool searchInBST(node* root, int key)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data == key)
    {
        return true;
    }
    if(key < root->data)
    {
        return searchInBST(root->left,key);
    }
    else
    {
        return searchInBST(root->right,key);
    }
}

node* deletionInBST(node* root, int d)
{
    ///We have traversed the tree and we cannot find the given data in BST
    if(root==NULL)
    {
        return NULL;
    }
    if(d < root->data)
    {
        root->left = deletionInBST(root->left,d);
    }
    else if(d== root->data)
    {
        ///case 1 - when 0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        ///case 2 - when 1 child
        if(root->left!=NULL && root->right==NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;

        }
        ///case 3 - when 2 children

        if(root->left!=NULL && root->right!=NULL)
        {
            node* alter = root->right;
            while(alter->left!=NULL)
            {
                alter = alter->left;
            }
            root->data = alter->data;
            root->right = deletionInBST(root->right,alter->data);
        }
    }
    else
    {
        root->right = deletionInBST(root->right,d);
    }
    return root;

}
int main()
{
   node*root = NULL;
   root = buildBST(root);
   levelOrderPrint(root);
   cout<<endl;
   InOrderPrint(root);
   int key;
   cout<<endl<<"enter key "<<endl;
   cin>>key;
   if(searchInBST(root,key))
   {
       cout<<"found"<<endl;
   }
   else
   {
       cout<<" not found"<<endl;
   }
    root = deletionInBST(root,key);
    InOrderPrint(root);
   cout<<endl<<"enter key "<<endl;
   cin>>key;
    root = deletionInBST(root,key);
    InOrderPrint(root);
     cout<<endl<<"enter key "<<endl;
   cin>>key;
    root = deletionInBST(root,key);
    InOrderPrint(root);
    return 0;
}

/*

9 7 12 6 8 10 13 -1
9
7 12
6 8 10 13

6 7 8 9 10 12 13
enter key
6
found


*/











