#include<iostream>
using namespace std;
void print_matrix(int a[][10],int r, int c)
{

     for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{

    int a[10][10]={0};
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    print_matrix(a,r,c);
    return 0;
}
