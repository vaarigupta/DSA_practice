#include<iostream>
#include<map>
#include<vector>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data =d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node*& root)
{
   int d;
   cin>>d;
   if(d== -1)
   {
       return NULL;
   }
    root = new node(d);
   root->left = buildTree(root->left);
   root->right = buildTree(root->right);
   return root;

}
void preOrderPrint(node * root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);

}
void verticalOrderPrint(node* root, map<int,vector<int> > &m, int d)
{
    if(root==NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    verticalOrderPrint(root->left,m,d-1);
    verticalOrderPrint(root->right,m,d+1);
}

int main()
{
    node* root = NULL;
    root = buildTree(root);
    preOrderPrint(root);
    cout<<endl;
    map<int, vector<int> > m;
    verticalOrderPrint(root,m,0);
    for(auto i =m.begin();i!=m.end();i++)
    {
        cout<<i->first<<" ->";
        for(auto it=0;it<i->second.size();it++)
        {
            cout<<i->second[it]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

/*



5 6 8  -1 -1 9 -1 -1 7 10 -1 -1 11 -1 -1
5 6 8 9 7 10 11
-2 ->8
-1 ->6
0 ->5 9 10
1 ->7
2 ->11

*/
