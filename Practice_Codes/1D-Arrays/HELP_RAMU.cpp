#include<iostream>
#include<vector>
using namespace std;
void help_ramu(int c1, int c2, int c3, int c4, int n, int m, vector<int> rick, vector<int> cab)
{
	int rickCost =0, cabCost = 0;
	for(int i=0;i<n;i++)
	{
		rickCost += min(c1*rick[i],c2);

	}
	for(int i=0;i<m;i++)
	{
		cabCost += min(c1*cab[i],c2);
	}
	rickCost = min(rickCost,c3);
	cabCost = min(cabCost,c3);
	int ans = min(rickCost+cabCost,c4);
	cout<<ans<<endl;

}
void printVector(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main() {
	int t,c1,c2,c3,c4,n,m;
	cin>>t;
	while(t--)
	{
    cin>>c1>>c2>>c3>>c4>>n>>m;
	vector<int> rick;
	vector<int> cab;
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		rick.push_back(no);
	}
	printVector(rick);
	for(int i=0;i<m;i++)
	{
		int no;
		cin>>no;
		cab.push_back(no);
	}
	printVector(cab);
	int rickCost =0, cabCost = 0;
	for(int i=0;i<n;i++)
	{
		rickCost += min(c1*rick[i],c2);

	}
	for(int i=0;i<m;i++)
	{
		cabCost += min(c1*cab[i],c2);
	}
	rickCost = min(rickCost,c3);
	cabCost = min(cabCost,c3);
	int ans = min(rickCost+cabCost,c4);
	cout<<ans<<endl;
	}
	return 0;
}

/*

2
1 3 7 19
2 3
2 5
4 4 4
4 3 2 1
1 3
798
1 2 3


1
1 3 7 19
2 3
2 5
4 4 4
*/
