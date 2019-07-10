#include<iostream>
using namespace std;
void read_matrix(int a[][10],int r, int c)
{

}
void print_matrix(int a[][10],int r, int c)
{


}
int main()
{
    int a[10][10]={0};
    int r,c;
    cin>>r>>c;
      for(int i=0;i<r;i++)
    {
        for(int j=0;i<c;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;i<c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
//    read_matrix(a,r,c);
//    print_matrix(a,r,c);
    return 0;
}
