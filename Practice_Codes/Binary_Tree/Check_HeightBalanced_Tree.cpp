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

pair<int,bool> heightBalanced(node* root)
{
    pair<int,bool> p;
    if(root==NULL)
    {
        p.first= 0;
        p.second = true;
        return p;
    }
    if(root->left==NULL && root->right==NULL)
    {
        p.first = 1;
        p.second = true;
        return p;
    }
    pair<int,bool> l = heightBalanced(root->left);
    pair<int,bool> r = heightBalanced(root->right);
    p.first = max(l.first,r.first) + 1;
    int k = abs(l.first - r.first);
    if(k<=1 && l.second && r.second)
    {
        p.second = true;
    }
    else
    {
        p.second = false;
    }
    return p;
}
int main()
{

    node* root = NULL;
    root = buildTree(root);
    cout<<"Level order Print :"<<endl;
    levelOrderPrint(root);
    cout<<endl;
    pair<int,bool> p = heightBalanced(root);
    if(p.second)
    {
        cout<<"Yes balanced :"<<endl;
    }
    else
    {
        cout<<"Not Balanced : "<<endl;
    }
    return 0;
}

/*

right Skew tree
8 -1 3 -1 4 -1 6 -1 7 -1 -1
Level order Print :
8
3
4
6
7

Height of tree : 5

Total nodes in tree : 5

Sum of  nodes in tree : 28

Diameter of tree : 5

-----------------------------------

Binary tree
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
Level order Print :
8
10 3
1 6 14
9 7 13

Height of tree : 4

Total nodes in tree : 9

Sum of  nodes in tree : 71
*/








