#include<iostream>
#include<cstring>
using namespace std;
template<typename t>
class node
{
public:
    string key;
    t value;
    node<t> *next;

    node(string k, t v)
    {
        key = k;
        value = v;
        next = NULL;
    }
    /// recursive destructor call- will delete the entire Linked list only by giving address of first node
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};

template<typename t>
class hashTable
{
    node<t>** buckets;
    int cs, ts;
public:
    int hashFn(string key)
    {
        int l = key.length();
        int ans =0, p=1;
        for(int i=0;i<l;i++)
        {
            ans += key[l-i-1]*p;

            ans %= ts;
            p *= 37;
            p %=ts;
        }
        return ans;
    }
    hashTable(int ds =7)
    {
        cs=0;
        ts= ds;
        buckets = new node<t>*[ts];

        for(int i=0;i<ts;i++)
        {
            buckets[i] = NULL;
        }
    }

    void insertHT(string key, t value)
    {
        int index = hashFn(key);
        node<t> *n = new node<t>(key,value);
        n->next = buckets[index];
        buckets[index] = n;
        cs++;

        float load_factor = (float)cs/ts;
        if(load_factor>0.7)
        {
            cout<<"Load factor is "<<load_factor<<endl;
            rehash();
        }

    }
    void rehash()
    {
        node<t>** oldBuckets = buckets;
        cs = 0;
        int oldTS = ts;
        ts = ts*2;

        buckets = new node<t>*[ts];
        for(int i=0;i<ts;i++)
        {
            buckets[i] =NULL;
        }

        for(int i=0;i<oldTS;i++)
        {
            node<t>* temp = oldBuckets[i];
            if(temp!=NULL)
            {
                while(temp!=NULL)
                {
                    insertHT(temp->key,temp->value);
                    temp = temp->next;
                }
                 delete oldBuckets[i];
            }
        }
        delete [] oldBuckets;

    }
    void printHT()
    {
        for(int i=0;i<ts;i++)
        {
            node<t>* temp = buckets[i];
            cout<<"Bucket "<<i<<" - ";
            while(temp!=NULL)
            {
                cout<<temp->key<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    t* searchHT(string key)
    {
        int idx = hashFn(key);
        node<t> *temp = buckets[idx];

        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return &(temp->value);
            }
            temp = temp->next;
        }
        return NULL;
    }

    void eraseHT(string key)
    {
        int idx = hashFn(key);
        node<t> * temp = buckets[idx];
        node<t> * prev = NULL;
        /// deletion at head
        if(temp->key == key)
        {
            prev = temp;
            temp = temp->next;
            buckets[idx] = temp;
            delete prev;
            return;

        }

        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;

        }
        if(temp==NULL)
        {
            return;
        }
    }

    t& operator[](string key)
    {
        t* findBucket = searchHT(key);
        if(findBucket==NULL)
        {
            t garbage;
            insertHT(key,garbage);
            findBucket = searchHT(key);
            return *findBucket;

        }
        return *findBucket;
    }

};

int main()
{
    hashTable<int> h(11);
    h.insertHT("Mango",100);
    h.insertHT("Banana",200);
    h.insertHT("Litchi",150);
    h.insertHT("Guava",300);
    h["papaya"] = 250;
    h["pineapple"] = 90;
    h["apple"] = 80;///insertion
//    h.insertHT("Pineapple",400);
//    h.insertHT("Apple",500);
//     h.insertHT("Peach",500);
//      h.insertHT("Grapes",500);
//       h.insertHT("Strawberry",500);
//        h.insertHT("Papaya",500);
    h.printHT();
    cout<<"Before update :"<<h["apple"]<<endl;
    h["apple"] = 140;///update
    cout<<"After update :"<<h["apple"]<<endl;///search
//    string key;
//    cin>>key;
//
//    int *found = h.searchHT(key);
//    if(found ==NULL)
//    {
//        cout<<key<<" not found "<<endl;
//    }
//    else
//    {
//        cout<<"Value :"<<(*found)<<endl;
//    }
//    cin>>key;
//    found = h.searchHT(key);
//    if(found ==NULL)
//    {
//        cout<<key<<" not found "<<endl;
//    }
//    else
//    {
//        cout<<"Value :"<<(*found)<<endl;
//    }
//    cin>>key;
//    found = h.searchHT(key);
//    if(found ==NULL)
//    {
//        cout<<key<<" not found "<<endl;
//    }
//    else
//    {
//        cout<<"Value :"<<(*found)<<endl;
//    }
//    string delKey;
//    cin>>delKey;
//    h.eraseHT(delKey);
//    h.printHT();
//    cin>>delKey;
//    h.eraseHT(delKey);
//    h.printHT();
//    cin>>delKey;
//    h.eraseHT(delKey);
//    h.printHT();
    return 0;
}

/*

Bucket 0 - Guava->Mango->
Bucket 1 - Pineapple->
Bucket 2 - Litchi->
Bucket 3 -
Bucket 4 -
Bucket 5 -
Bucket 6 - Apple->Banana->

Guava
Value :300
Mango
Value :100
Banana
Value :200

Litchi
Bucket 0 - Guava->Mango->
Bucket 1 - Pineapple->
Bucket 2 -
Bucket 3 -
Bucket 4 -
Bucket 5 -
Bucket 6 - Apple->Banana->

Apple
Bucket 0 - Guava->Mango->
Bucket 1 - Pineapple->
Bucket 2 -
Bucket 3 -
Bucket 4 -
Bucket 5 -
Bucket 6 - Banana->

Guava
Bucket 0 - Mango->
Bucket 1 - Pineapple->
Bucket 2 -
Bucket 3 -
Bucket 4 -
Bucket 5 -
Bucket 6 - Banana->


*/
