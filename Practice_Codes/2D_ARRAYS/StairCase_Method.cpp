#include<iostream>
using namespace std;

/*

ARRAYS- Find a no in 2D array which is sorted along the rows and columns
Take as input as sorted two-d array and a key to find in that array

///Using staircase approach

*/
void printArray(int a[][10], int r, int c)
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
///Time complexity - O(2N)
void stairCase(int a[][10], int r, int c, int key)
{
   int i = 0, j=c-1;
   while(i<r && j>=0)
   {
       if(a[i][j]==key)
       {
           cout<<key<<" is found ("<<i<<","<<j<<")"<<endl;
           return;
       }
       else if(a[i][j]<key)
       {
           i++;
       }
       else
       {
           j--;
       }
   }

        cout<<"No such element found "<<endl;
}
int main()
{
    int a[10][10]={0};
    int r,c,key;
    cout<<"Enter rows and cols :"<<endl;
    cin>>r>>c;
    cout<<"Enter elements :"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    printArray(a,r,c);
    cout<<"Enter key :"<<endl;
    cin>>key;
   stairCase(a,r,c,key);

    return 0;
}




