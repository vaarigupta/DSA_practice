#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<cstdio>
using namespace std;

int main()
{

    int k_arr=3,n1=4,n2=4,n3=3;
    int output[11];
    int a[] = {1,3,6,7};
    pair<int, int*> p1 = make_pair(n1,a);
    int b[] = {2,4,5,8};
     pair<int, int*> p2 = make_pair(n2,b);
    int c[] = {0,9,10};
     pair<int, int*> p3 = make_pair(n3,c);
    priority_queue<int , vector<int> , greater<int> > pq;
    int i=0, j=0, k=0,cs=0, iter=0;
    while(i<n1 || j<n2 || k<n3)
    {
        if(cs<k_arr)
        {
            pq.push(a[i]);
            i++;
            cs++;
        }
        if(cs<k_arr)
        {
            pq.push(b[j]);
            j++;
            cs++;
        }
        if(cs<k_arr)
        {
            pq.push(c[k]);
            k++;
            cs++;
        }
        int no = pq.top();
        output[iter] = no;
        iter++;
        cs--;
        pq.pop();
        if(i==n1 || j==n2 || k==n3)
        {
            pq.push(INT_MAX);
        }


    }
    for(int i=0;i<11;i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}


