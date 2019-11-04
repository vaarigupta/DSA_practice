#include <iostream>
#include<cstring>
#include<vector>
#define range 1050000
using namespace std;
vector<int> subset(vector<int> notes , int no)
{
    vector<int> sub(notes.size());
    int i =0;
    while(no>0)
    {
        if(no&1)
        {
            sub.push_back(notes[i]);
        }
        i++;
        no >>= 1;

    }
    return sub;
}
void print(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
bool sumPossible(vector<int> notes , int n , int m)
{
        for(int i=0;i<=range;i++)
        {
 //           vector<int> sub;
//            int k =0;
//            while(i>0)
//            {
//                if(i&1)
//                {
//                    sub.push_back(notes[k]);
//                }
//                k++;
//                i >>= 1;
//
//            }
        vector<int> sub = subset(notes, i);
        ///print(sub);
        int ans = 0;
        for(int i=0;i<sub.size();i++)
        {
            ans += sub[i];
        }
        if(ans==m)
        {
            return true;
        }
    }
    return false;
}
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<int> notes(21);
        for(int i=0;i<n;i++)
        {
            int no;
            cin>>no;
            notes.push_back(no);
        }
        if(sumPossible(notes,n,m))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
	return 0;
}

