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


node* BTpreInOrder(int *pre, int *in, int s, int e)
{
    static int k = 0;
    if(s>e)
    {
        return NULL;
    }
    ///iteratively pick one element from preOrder array and make it a node
    node* n = new node(pre[k]);
    int mid = -1;

    ///look for the picked element in Inorder array and save its index
    for(int i=s;i<=e;i++)
    {
        if(pre[k]==in[i])
        {
            mid = i;
            break;
        }
    }
    k++;
    ///divide the inorder array recursively and make subtrees left and right
    n->left = BTpreInOrder(pre,in,s, mid-1);
    n->right = BTpreInOrder(pre,in,mid+1,e);
    return n;
}
int main()
{
    int pre[] = {1,2,3,4,8,5,6,7};
    int in[] = {3,2,8,4,1,6,7,5};
    int n = sizeof(pre)/sizeof(int);
    node* root = BTpreInOrder(pre, in , 0,n-1);
    cout<<"Level order Print :"<<endl;
    levelOrderPrint(root);
    cout<<endl;

    return 0;
}

/*

Level order Print :
1
2 5
3 4 6
8 7


*/










