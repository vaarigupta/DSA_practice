#include<iostream>
#include<list>
using namespace std;

int main()
{
    int n;
   cin>>n;
   while(n--)
   {
    int a,b,ans =0;
    cin>>a>>b;
    for(int i= a;i<=b;i++)
    {
        ans += __builtin_popcount(i);
    }
    cout<<ans<<endl;

   }


    return 0;
}

/*

0->1,2,
1->0,4,3,
2->0,4,
3->1,4,
4->1,2,3,

*/

