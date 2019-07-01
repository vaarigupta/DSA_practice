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
node* input_level_order()
{
    int d;
    cin>>d;
    node* n = new node(d);
    queue<node*> q;
    q.push(n);
    while(d!=-1)
    {
        cout<<"enter left node :"<<endl;
        cin>>d;
        n->left = new node(d);
        q.push(n->left);
        cout<<"enter  right node :"<<endl;
        cin>>d;
        n->right = new node(d);
        q.push(n->right);

    }
    return n;
}

node* level_order_build()
{

    int d;
    cin>>d;
    node* root = new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* f = q.front();
        q.pop();
         int c1,c2;
         cin>>c1>>c2;
         if(c1!= -1)
         {
             f->left = new node(c1);
             q.push(f->left);
         }
         if(c2!=-1)
         {
             f->right = new node(c2);
             q.push(f->right);
         }

    }
    return root;
}
void levelOrderPrint(node* root)
{
    queue <node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* f = q.front();
        cout<<f->data;
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
int main()
{
    node* root = NULL;
    root = level_order_build();
    levelOrderPrint(root);
    return 0;
}

