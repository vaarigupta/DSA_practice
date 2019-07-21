#include<iostream>
using namespace std;
long int a[1000000] = {0};
long int n;
int main()
{
    int freq[5]={0};
    int k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }


    for(int i=0;i<n;i++)
    {
        freq[a[i]]++;
    }

    for(int i=0;i<3 && k<n;i++)
    {
        while(freq[i]>=0)
        {
            a[k++] = i;
            freq[i]--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}


