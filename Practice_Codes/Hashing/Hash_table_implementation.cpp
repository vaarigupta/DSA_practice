#include<iostream>
#include<cstring>
using namespace std;
class node
{
    public:
    string key;
    int value;
    node * next;

    node(string k, int v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class hashTable
{
    node** ptrArray;
    int cs, ts=7;
public:
    hashTable(int ds=7)
    {
        ptrArray = new node*[ds];
        for(int i=0;i<ds;i++)
        {
            ptrArray[i] = NULL;
        }
    }

    int hashFn(string key)
    {
        int l = key.length();
        int ans =0, p=1;
        for(int i=0;i<l;i++)
        {
            ans += key[l-i-1]*p;
            p *= 37;
            p %= ts;/// to prevent overflow of no
            ans %= ts; /// to limit the indexes within the table size

        }
        return ans;
    }

    void insertNode(string key, int value)
    {
        int index = hashFn(key);

        node* n = new node(key,value);
        n->next = ptrArray[index];
        ptrArray[index] = n;
    }
    void print()
    {
        node* temp;

        for(int i=0;i<ts;i++)
        {
            temp = ptrArray[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<" , ";
                temp = temp->next;
            }
            cout<<endl;

        }
    }

    node* searchKey(string key)
    {
        int idx = hashFn(key);
        node* temp = ptrArray[idx];
        while(temp!=NULL )
        {
            if(temp->key==key)
            {
               return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    ///complete  it ?????
    node* deleteNode(string key)
    {

    }

};
int main()
{
    hashTable h(57);
    h.insertNode("apple",10);
    h.insertNode("mango",20);
    h.insertNode("banana",30);
    h.insertNode("grapes",40);
    h.insertNode("litchi",50);
    h.insertNode("strawberry",60);
    h.insertNode("pear",10);
    h.insertNode("cherry",20);
    h.insertNode("guava",30);
    h.insertNode("orange",40);
    h.insertNode("kiwi",50);
    h.insertNode("papaya",60);
    h.print();
    string input;
    cout<<"Enter the key :"<<endl;
    cin>>input;
    node * temp = h.searchKey(input);
    if(temp==NULL)
    {
    cout<<"Not found"<<endl;
    }
    else
    {
        cout<<temp->value<<endl;
    }


    return 0;
}
