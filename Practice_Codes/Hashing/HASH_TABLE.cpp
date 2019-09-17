#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
class node
{
    public:
    string key;
    T value;
    node<T> *next;

    node(string k, T v)
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
template< typename T>
class hashtable
{
    int cs;
    int ts;
    node<T> **buckets;
    public:
    int hashFn(string str)
    {
        int L = str.length();
        int ans =0,p=1;
        for(int i=0;i<L;i++)
        {
            ans += str[L-i-1]*p;
            p *= 37;
            ans %= ts;
            p %= ts;

        }
        return ans;
    }
    hashtable(int ds = 7)
    {
        cs = 0;
        ts = ds;
        buckets = new node<T>*[ts];
        for(int i=0;i<ts;i++)
        {
            buckets[i] = NULL;
        }

    }
    void rehash()
    {
        int oldts = ts;
        cs =0;
        ts *= 2;
        node<T>** oldbucket = buckets;
        buckets = new node<T>*[ts];
        for(int i=0;i<ts;i++)
        {
            buckets[i] = NULL;
        }
        for(int i=0;i<oldts;i++)
        {
            node<T>* temp = oldbucket[i];
            while(temp!=NULL)
            {
                insertKV(temp->key,temp->value);
                cs++;
                temp = temp->next;
            }
            delete oldbucket[i];
        }
        delete [] oldbucket;



    }
    void insertKV(string str, T val)
    {
        int i = hashFn(str);
        node<T> *n = new node<T>(str,val);
        n->next = buckets[i];
        buckets[i] = n;
        cs++;

        float load_factor = (float)cs/ts;
        if(load_factor >= 0.7)
        {
            rehash();
        }

    }
    T& operator[] (string key)
    {
        T* temp = searchKV(key);
        if(temp==NULL)
        {
            T garbage;
            insertKV(key,garbage);

            T* value = searchKV(key);
            return *value;

        }
        return *temp;
    }
    void deleteKV(string key)
    {
        int i = hashFn(key);
        node<T> *temp = NULL;
        node<T> *nextptr = buckets[i];
        if(nextptr->key==key)
        {
            buckets[i] = nextptr->next;
            delete temp;
            delete nextptr;
            return;
        }
        while(nextptr!=NULL)
        {
            if(nextptr->key==key)
            {
                temp->next = nextptr->next;
                delete temp;
                delete nextptr;
                return;
            }
            temp = nextptr;
            nextptr = nextptr->next;
        }
        if(nextptr==NULL)
        {
            delete temp;
            delete nextptr;
            //cout<<"No key found "<<endl;
            return;
        }

    }
    T* searchKV(string key)
    {
        int i = hashFn(key);
        node<T>* temp = buckets[i];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &(temp->value);
            }
            temp = temp->next;
        }
        if(temp==NULL)
        {
            return NULL;
        }
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            cout<<"bucket "<<i<<" ->";
            node<T> *temp = buckets[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<","<<temp->value<<" || ";
                temp = temp->next;
            }
            cout<<endl;
        }
        cout<<endl;
    }



};
int main()
{
    hashtable<int> h;
    h.insertKV("Apple",89);
    h.insertKV("Banana",56);
    h.insertKV("Grapes",78);
    h.insertKV("Papaya",67);
    h.insertKV("litchi",34);
    h["Plum"] = 120;///insertion
    h["Apple"] = 90;///updation

//    h.insertKV("Guava",45);
//    h.insertKV("Strawberry",11);
//    h.insertKV("Pear",33);
    //h.deleteKV("Apple");
    h.print();

    int *temp = h.searchKV("Apple");
    if(temp!=NULL)
    {
       cout<<(*temp)<<" ";
    }
    else
    {
       cout<<"Not found "<<endl;
    }
    cout<<endl;
    cout<<h["Grapes"]<<endl;///searching
//    h.deleteKV("Pear");
//    h.deleteKV("Banana");
//    h.deleteKV("Papaya");
//    //h.deleteKV("yee");
//    h.print();

    return 0;
}
