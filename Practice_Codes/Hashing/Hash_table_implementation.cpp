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

    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};

class hashTable
{
    node** ptrArray;
    int cs, ts;
public:
    hashTable(int ds=7)
    {
        cs=0;
        ts=7;
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
            p %= ts;/// to prevent overflow of number
            ans %= ts; /// to limit the indexes within the table size

        }
        return ans;
    }
    void rehash()
    {
        node** oldPtrArray = ptrArray;
        int oldts = ts;
        ts <<=1;
        ptrArray = new node*[ts];

        ///creation of new hashTable and pointing each node pointer to NULL
        for(int i=0;i<ts;i++)
        {
            ptrArray[i] = NULL;
        }

        ///copying elements
        for(int i=0;i<oldts;i++)
        {
            node* temp = oldPtrArray[i];
            if(temp!=NULL)
            {
               while(temp!=NULL)
            {
                insertNode(temp->key,temp->value);
                temp = temp->next;
            }
            delete oldPtrArray[i];///calling the recursive destructor
            }

        }

        delete []oldPtrArray;

    }
    void insertNode(string key, int value)
    {
        int index = hashFn(key);

        node* n = new node(key,value);
        n->next = ptrArray[index];
        ptrArray[index] = n;

        cs++;
        float load_factor = (float)cs/ts;
        if(load_factor>= 0.7)
        {
            cout<<"Load factor is"<<load_factor<<endl;
            rehash();
        }
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
    void deleteNode(string key)
    {
        int idx = hashFn(key);
        node* temp = ptrArray[idx];

        ///deletion at head
        if(temp->key == key)
        {
            ptrArray[idx] = temp->next;
            temp->next = NULL;
            delete temp;
        }
        ///deletion in middle
        node* prev = temp;
        while(temp!=NULL)
        {
            if(temp->key == key)
            {
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            ///deletion at end
            if(temp->next==NULL && temp->key == key)
            {
               prev->next = NULL;
               delete temp;
            }
            prev = temp;
            temp = temp->next;
        }
    }

};
int main()
{
    hashTable h(7);
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
    cout<<"Enter the key to delete :"<<endl;
    cin>>input;
    h.deleteNode(input);
    h.print();
        cout<<"Enter the key to delete :"<<endl;
    cin>>input;
    h.deleteNode(input);
    h.print();

        cout<<"Enter the key to delete :"<<endl;
    cin>>input;
    h.deleteNode(input);
    h.print();

        cout<<"Enter the key to delete :"<<endl;
    cin>>input;
    h.deleteNode(input);
    h.print();

        cout<<"Enter the key to delete :"<<endl;
    cin>>input;
    h.deleteNode(input);
    h.print();
    return 0;
}
