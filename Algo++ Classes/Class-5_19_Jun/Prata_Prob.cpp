#include <iostream>
#include<climits>
using namespace std;
bool pratas_possible(int *ranks, int prata,int cook, int min_time)
{
    int count_prathas =0;
    int curr_time = 0,i=0;
    int r=0;
    for( r=0;r<cook;r++)
    {
        i=0;
        curr_time = 0;
        while(curr_time<=min_time)
        {
            i++;
            curr_time += ranks[r]*i;

        }
        count_prathas += (i-1);
        if(count_prathas >=prata)
        {
            return true;
        }

    }
    if(count_prathas<prata)
    {
        return false;
    }
    if(r==cook && count_prathas==prata)
    {
        return true;
    }

}
int min_time(int *ranks, int prata,int cook, int max_rank)
{
    int s =0;
    int e = (max_rank*(prata)*(prata+1))/2;
    int mid =0;
    int ans = INT_MAX;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(pratas_possible(ranks,prata,cook,mid))
        {
            ans = min(ans,mid);
            e = mid-1;

        }
        else
        {

            s = mid+1;
        }

    }
    return ans;


}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ///P - no of pratas required
	    /// C - No of Cooks
        int Prata, Cook;
        cin>>Prata>>Cook;
        int ranks[51]; /// denotes rank of each cook
        int max_rank = INT_MIN;
        for(int i=0;i<Cook;i++)
        {
            cin>>ranks[i];
            max_rank = max(max_rank, ranks[i]);
        }
        cout<<min_time(ranks,Prata,Cook, max_rank)<<endl;
	}
	return 0;
}
