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

///DFS
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
///BFS
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
    while(!q.empty())
    {
        node *f = q.front();
        cout<<f->data<<", ";
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
void levelOrderPrint2(node* root)
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
int main()
{

    node* root = NULL;
    root = buildTree(root);
     cout<<endl;
    cout<<"Level order Print 1:"<<endl;
    levelOrderPrint1(root);
    cout<<endl;
    cout<<"Level order Print 2:"<<endl;
    levelOrderPrint2(root);
    return 0;
}

/*



8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

Level order Print 1:
8, 10, 3, 1, 6, 14, 9, 7, 13,
Level order Print 2:
8
10 3
1 6 14
9 7 13

*/

