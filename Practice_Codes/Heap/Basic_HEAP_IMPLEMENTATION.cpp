#include<iostream>
#include<vector>
using namespace std;
class heap
{
    vector<int> v;
    bool minHeap;
public:
    heap(bool type=true)
    {
        minHeap = type;
        v.push_back(-1);
    }
    bool compare(int a, int b)
    {
        if(minHeap)
        {
            return a<b;
        }
        else
        {
            return a>b;
        }
    }
    void push(int data)
    {
        v.push_back(data);
        ///take it to the current position - To restore heap property
        int index = v.size() -1;
        int parent = index/2;
        while(index>1 && compare(v[index],v[parent]))
        {
            swap(v[index],v[parent]);
            index = parent;
            parent = parent/2;
        }
    }
    int top()
    {
        return v[1];
    }
    bool isEmpty()
    {
        return (v.size()==1);
    }
    void heapify(int i)
    {
        int left = 2*i;
        int right = 2*i +1;
        int minIndex = i;
        if(left< v.size() && compare(v[left],v[i]))
        {
            minIndex = left;
        }
        if(right < v.size() && compare(v[right],v[minIndex]))
        {
            minIndex = right;
        }
        if(minIndex!=i)
        {
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }
    }
    void pop()
    {
        int last = v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }

};
int main()
{
    heap h;
    h.push(23);
    h.push(2);
    h.push(67);
    h.push(1);
    h.push(45);
    while(!h.isEmpty())
    {
        cout<<h.top()<<endl;
        h.pop();
    }
    return 0;
}
