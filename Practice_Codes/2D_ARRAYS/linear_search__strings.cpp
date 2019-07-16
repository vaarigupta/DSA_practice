#include<iostream>
#include<cstring>
using namespace std;
int linearSearch(char a[][20],int n, char *key)
{
    int i=0;
     for(i=0;i<n;i++)
    {

        if(strcmp(a[i],key)==0)
        {
            return i;
        }
    }
    if(i==n)
    {
        return -1;
    }
}
int main()
{
    char a[10][20];
    int n;
    char key[100];
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cin.getline(a[i],20);
    }
    cout<<"Enter key :"<<endl;
    cin.getline(key,100);
    int ans = linearSearch(a,n,key);
    if(ans!= -1)
    {
       cout<<key<<" found at "<<ans<<endl;
    }
    else
    {
        cout<<key<<"is not found at "<<endl;
    }


    return 0;
}
