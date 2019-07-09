#include<iostream>
#include<cstring>
using namespace std;
char max_freq(char *a)
{
    int n = strlen(a), maxNo=-1,ans=0;
    int freq[256]= {0};
    for(int i=0;i<n;i++)
    {
        int val = a[i] - '\0';
        freq[val]++;
        if(freq[val]>maxNo)
        {
            maxNo = freq[val];
            ans = val;

        }
    }
    return (char)ans;
}
int main()
{
     char a[1000];
    cin.getline(a,1000);
    cout<<max_freq(a);

    return 0;
}
