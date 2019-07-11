#include<iostream>
using namespace std;

/*

ARRAYS- Find a no in 2D array which is sorted along the rows and columns
Take as input as sorted two-d array and a key to find in that array


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
void searchKey(int a[][10], int r, int c, int key)
{
    int row=0;
    for(;row<r;row++)
    {
        if((a[row][0]<=key) && (key<=a[row][c-1]))
        {
            for(int col=0;col<c;col++)
            {
                if(a[row][col]==key)
                {
                    cout<<key<<" is found at ("<<row<<","<<col<<")"<<endl;
                    return;
                }
            }
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
   searchKey(a,r,c,key);

    return 0;
}



