#include<iostream>
using namespace std;
bool canPlace(int *st, int n , int c, int sep)
{
    int cows = 1;
    int last_cows = st[0];
    for(int i=1;i<=(n-1);i++)
    {
        int current_stall = st[i];
        if(current_stall-last_cows >= sep)
        {
            cows++;
            last_cows = current_stall;
            if(cows==c)
            {
                return true;
            }
        }

    }
        return false;
}
int aggressive_cows(int *st, int c,int n)
{
    int s=0;
    int e = st[n-1] - st[0];
    int ans=0;
    while(s<=e)
    {

        int mid = (s+e)/2;
        if(canPlace(st,n,c,mid))
        {
            ans = mid;
            s= mid+1;
        }
        else
        {
            e = mid-1;
        }

    }

}

int main()
{
    int c=3;
    int stalls[]= {1,2,4,8,9}; ///Sorted coordinates
    int n = sizeof(stalls)/sizeof(int);
    cout<<aggressive_cows(stalls,c,n);
    return 0;

}
