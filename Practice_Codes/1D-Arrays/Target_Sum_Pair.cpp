#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,key,a[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    cin>>key;
    sort(a,a+n);
    int i=0, j =n-1;
    while(i<j)
    {
        if((a[i]+a[j])==key)
        {
            cout<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }
        else if((a[i]+a[j])<key)
        {
            i++;
        }
        else
        {
            j--;
        }

    }



    return 0;
}


//   Bruteforce approach
// for(int i=0;i<n;i++)
//    {
//        for(int j=i+1;j<n;j++)
//        {
//            if(a[i]+a[j]== key)
//            {
//                cout<<a[i]<<" and "<<a[j]<<endl;
//            }
//        }
//    }
/*

ARRAYS-TARGET SUM PAIRS
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.


Input Format:
The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints:
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input
5
1
3
4
2
5
5
Sample Output
1 and 4
2 and 3
*/
