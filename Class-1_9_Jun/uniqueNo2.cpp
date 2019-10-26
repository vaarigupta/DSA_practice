#include<iostream>
using namespace std;
void findTwoUniqueNo(int *a, int n)
{
    int res=0;
   for(int i=0;i<n;i++ )
   {
       res ^= a[i];
   }
   int j=0, temp =res;

   while(temp>0)
   {
       if(temp&1)
       {
           break;
       }
       temp >>= 1;
       j++;
   }
    int mask = 1<<j;
    /// this mask will help us to nullify other number
    ///bcz set bit comes only from only one of the numbers
    /// and ANDing of mask with first number will definitely give only first number
    int firstNo = 0;
    for(int i=0;i<n;i++)
    {
        if((mask&a[i])!=0)
        {
           firstNo  ^= a[i];
        }

    }
    int secondNo = firstNo^res;
    cout<<"Unique No's are : "<<firstNo<<" "<<secondNo<<endl;

}
int main()
{
    int a[] = {1,1,2,2,3,3,5,6};
    int n = sizeof(a)/sizeof(int);
    findTwoUniqueNo(a,n);
    return 0;
}


