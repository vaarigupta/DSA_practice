#include<iostream>
#include<vector>
using namespace std;
/*

We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. Find the unique number. Only use - bitwise operators, and no extra space.

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
N < 10^5

Output Format
Output a single line containing the unique number

Sample Input
7
1 1 1 2 2 2 3
Sample Output
3
Explanation
3 is present only once

*/
int binToDec(int *a,int n)
{
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += ((a[i]%3)*(1<<i));
    }
    return ans;
}
int uniqueNo3(int *a, int n)
{
    int no[64] = {0};
    for(int i=0;i<n;i++)
    {
        int x = a[i];
        int j=0;
        while(x>0)
        {
            no[j] += (x&1);
            x >>= 1;
            j++;
        }
    }

    int ans =  binToDec(no,64);
    return ans;




}
 int singleNumber(vector<int> nums) {

        int size = 8*sizeof(int);
        //return size;
        int sumOfBits = 0 , ans=0;
        for(int i=0;i<size;i++)
        {
            sumOfBits = 0;
            for(int j=0;j<nums.size();j++)
            {
                sumOfBits += (nums[j]>>i)&1;

            }
            ans += (sumOfBits%3)*(1<<i);
           // pow_of_two *= 2;
        }
        return ans;

    }
int main()
{

//    int a[] = { 1,2,2,3,3,3,1,1,2,4};
//    int n = sizeof(a)/sizeof(int);
//    cout<<"Unique No : "<<uniqueNo3(a,n);
    vector<int> nums = { 1,2,2,3,3,3,1,1,2,4};
    cout<<singleNumber(nums)<<endl;
    return 0;
}
