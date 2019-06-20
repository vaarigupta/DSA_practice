#include<iostream>
using namespace std;
int binary_search( int s, int e, int key)
{
    int mid=(s+e)/2;
    if(s>e)
    {
        return mid;
    }
    if(s<=e)
    {
        mid=(s+e)/2;
        if((mid*mid)==key)
        {
            return mid;
        }
        if((mid*mid)<key)
        {
            return binary_search(mid+1,e,key);
        }
        if((mid*mid)>key)
        {
            return binary_search(s,mid-1,key);
        }
    }

}
int main()
{
//    int a[] = {1,2,3,4,5,6,7,8};
//    int n = sizeof(a)/sizeof(int),key;
    int key;
    cout<<"Enter the value :"<<endl;
    cin>>key;
    int ans = binary_search(0,key,key);
    cout<<"Square Root :"<<ans<<endl;


    return 0;
}

