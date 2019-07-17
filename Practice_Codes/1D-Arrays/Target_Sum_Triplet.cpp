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

    int i=0, j =n-1,temp=0;
    for(int k=0;k<n-2;k++)
    {
        i= k+1;
        j = n-1;
        while(i<j)
    {
        if((a[k]+a[i]+a[j])==key)
        {
            cout<<a[k]<<", "<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }
        else if((a[k]+a[i]+a[j])>key)
        {
            j--;
        }
        else
        {
            i++;

        }

    }
    }



    return 0;
}

/*

ARRAYS-TARGET SUM TRIPLETS
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.

Input Format:
First line contains input N. Next N lines contains the elements of array and N+1 line contains target number.

Constraints:
Length of Array should be between 1 and 1000.

Output Format
Print all the triplet present in the array.

Sample Input
9
5
7
9
1
2
4
6
8
3
10
Sample Output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5

*/

