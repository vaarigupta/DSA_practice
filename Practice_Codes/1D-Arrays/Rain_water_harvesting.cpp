#include<iostream>
using namespace std;
int rain_water(int *a, int n)
{
   int left[100] = {0}, right[100] = {0},height=0;
   left[0] = a[0];
   for(int i=1;i<n;i++)
   {
       left[i] = max(a[i],left[i-1]);
   }
   right[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--)
   {
       right[i] = max(right[i+1],a[i]);
   }
   for(int i=0;i<n;i++)
   {
       int ans = min(left[i],right[i]) - a[i];
       if(ans>0)
       {
            height += ans;
       }

   }
   return height;
//   for(int i=0;i<n;i++)
//   {
//       cout<<left[i]<<" ";
//   }
//   cout<<endl;
//   for(int i=0;i<n;i++)
//   {
//       cout<<right[i]<<" ";
//   }
}
int main() {
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<rain_water(a,n);
	return 0;
}

/*

RAIN WATER HARVESTING
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units

Input Format:
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints:
Output Format
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5

*/

