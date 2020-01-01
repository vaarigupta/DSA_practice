#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	vector<int> arr1;
	vector<int> arr2;
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		arr1.push_back(no);
	}
	for(int i=0;i<m;i++)
	{
		int no;
		cin>>no;
		arr2.push_back(no);
	}
	int l1 = n , l2 = m;
	int last = max(n,m);
	vector<int> output(last + 1,0);
	int i = 0 , carry =0;
	while(l1>=0 && l2>=0)
	{
		output[i] = (carry + (arr1[l1-1] + arr2[l2 -1]))%10;
		carry =  (carry + (arr1[l1-1] + arr2[l2 -1]))/10;
		l1--;
		l2--;
		i++;
	}
	while(l1!=0 )
	{
		output[i] = (arr1[i] + carry)%10;
		carry = (arr1[i] + carry)/10;
		l1--;
		i++;
	}
	while(l2!=0 )
	{
		output[i] = (arr2[i] + carry)%10;
		carry = (arr2[i] + carry)/10;
		l2--;
		i++;
	}
	for(int k=i;k>=0;k--)
	{
		cout<<k<<", ";
	}
	cout<<"END";


	return 0;
}
