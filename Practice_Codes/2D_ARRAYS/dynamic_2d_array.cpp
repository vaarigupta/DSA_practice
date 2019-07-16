#include<iostream>
using namespace std;
///Allocating 2D array using dynamic memory allocation
int main()
{
    int **a = new int*[3];
    for(int i=0;i<3;i++)
    {
        a[i] = new int[4];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>a[i][j];
        }
    }
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<3;i++)
    {
        delete []a[i];
    }
    delete []a;
    return 0;
}

