#include<iostream>
using namespace std;
///generic class
template<typename T>
class node
{
    public:
    string key;
    T value;
    node<T> *next;

    node(string k, T v)
    {
        key = k;
        value =v;
        next = NULL;
    }


};
template<typename T>
class HashTable
{
    //int **arr=  new int*[10];
    node<T> **table;
    int table_size;
    int current_size;
    int hashFn(string key)
    {
        int ans = 0, p=1;
        for(int i=0;i<key.length();i++)
        {
            ans += (key[i]*p)%table_size;
            ans = ans%table_size;
            p = (p*29)%table_size;
        }
        return ans;
    }
    void rehash()
    {
        node<T> **oldtable = table;
        int oldtableSize = table_size;

        ///new table
        table_size = 2*table_size;
        table = new node<T> *[table_size];

        for(int i=0;i<table_size;i++)
        {
            table[i] = NULL;
        }

        current_size =0;
        for(int i=0;i<oldtableSize;i++)
        {
            node<T> *temp = oldtable[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            if(oldtable[i]!=NULL)
            {
                delete oldtable[i];
            }
        }
        delete [] oldtable;
    }
public:
    HashTable(int ds=7)
    {
        table_size =ds;
        current_size = 0;
        table = new node<T>*[table_size];

        for(int i=0;i<table_size;i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, int value)
    {
        int idx = hashFn(key);
        node<T> *n = new node<T>(key,value);
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        float load_factor = (current_size)/float(table_size);
        if(load_factor>0.7)
        {
            rehash();
        }
    }

    /// handle case of deletion at the head - update index of array pointer
    /// in the middle - like in Linked List
    /// at the end - like in Linked List
    void erase(string key)
    {


    }
    T* search(string key)
    {
        ///pointer to the value if found else NULL
        int idx = hashFn(key); 4
        node<T> * temp = table[idx];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &(temp->value);
            }
            temp = temp->next;
        }
    }
    void print()
    {
        ///iterate over all the buckets
        for(int i=0;i<table_size;i++)
        {
            cout<<"Buckets "<<i<<"-->";
            node<T> *temp = table[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<"-->";
                temp = temp->next;
                cout<<endl;
            }

        }
    }
    T& operator[](string key)
    {
        T* f = search(key);
        if(f==NULL)
        {
            T garbage;
            insert(key,garbage);
            f = search(key);
        }
        return *f;

    }

};
int main()
{
    HashTable<int> h;
    h.insert("apple",20);
     h.insert("guava",40);
      h.insert("banana",50);
      h.insert("cherry",60);
      h.insert("mango",70);
      h.insert("litchi",40);
      h.insert("pear",80);
      h.print();
        string fruit;
        cin>>fruit;

      int *price = h.search(fruit);
      if(price==NULL)
      {
          cout<<"Not found "<<endl;
      }
        else
        {
            cout<<"Price is "<<(*price)<<endl;
        }
        h["banana"] = 40;
        h["banana"] = 60;
        h["banana"] += 11;
        cout<<h["banana"]<<endl;
    return 0;
}

