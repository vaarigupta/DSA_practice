#include<iostream>
using namespace std;
bool isValidConfig(int *books, int n , int m , int mid)
{
    int student = 1;
    int current_pages = 0;
    for(int i=0;i<n;i++)
    {
        if(current_pages+books[i]>mid)
        {
            current_pages = books[i];
            student++;
            if(student>m)
            {
                return false;
            }

        }
        else
        {
            current_pages += books[i];
        }
    }
    return true;
}
int binarySearchBook(int *books, int n , int m)
{
    int total_pages=0;
    for(int i=0;i<n;i++)
    {
        total_pages += books[i];
    }
    int s = books[n-1] , e = total_pages;
    int finalAns=0;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(isValidConfig(books,n,m,mid))
        {
            finalAns = mid;
            e = mid-1;

        }
        else
        {
            s = mid+1;
        }
    }
    return finalAns;

}
int main()
{
    int t,n,m;
    int books[110];
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>books[i];
        }
        cout<<binarySearchBook(books,n,m)<<endl;
    }


    return 0;
}





