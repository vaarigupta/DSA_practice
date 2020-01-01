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

node* heightBalancedBST(int *a, int s, int e)
{
    int mid;
    node* root;
    if(s>e)
    {
        return NULL;
    }

    mid= (s+e)/2;
    root = new node(a[mid]);
    root->left = heightBalancedBST(a,s,mid-1);
    root->right = heightBalancedBST(a,mid+1,e);

    return root;

}
node* arrayToBST(int *a, int s, int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = arrayToBST(a,s,mid-1);
    root->right = arrayToBST(a,mid+1,e);
    return root;
}

void level_order_print(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *f = q.front();
        if(f==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
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
}
int main()
{
    int a[] = {1,2,3,4,5,6,7};
    int n = sizeof(a)/sizeof(int);
    node* root = arrayToBST(a,0,n-1);
    level_order_print(root);
    cout<<endl;
     root = heightBalancedBST(a,0,n-1);
    level_order_print(root);
    return 0;
}

