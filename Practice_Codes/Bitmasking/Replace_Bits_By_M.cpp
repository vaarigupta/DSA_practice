#include <iostream>
using namespace std;
int dec_to_bin(int n)
{
    int ans=0,ten_pow=1;
    while(n>0)
    {
        ans += ((n&1)*ten_pow);
        ten_pow*= 10;
        n >>= 1;
    }
    return ans;

}
int main() {
	int n,m,i,j;
	cin>>n>>m>>i>>j;
	cout<<"N : "<<dec_to_bin(n)<<" M: "<<dec_to_bin(m)<<endl;
	for(int k=i;k<=j;k++)
	{
	    int bit = m&1;
	    if(bit)
	    {
	        n = n | (1<<k);
	    }
	    else
	    {
	        n = n & (~(1<<k));
	    }
	    m >>= 1;
	}
	cout<<"Modified ans :"<<n<<" "<<dec_to_bin(n)<<endl;
	return 0;
}

/*

2048 21 2 6
N : 1215752192 M: 10101
Modified ans :2132 1216762292

*/
