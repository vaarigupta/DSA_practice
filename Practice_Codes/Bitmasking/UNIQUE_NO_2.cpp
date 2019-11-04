//#include<bits/stdc++.h>
//using namespace std;
//void printUnique(vector<int> v)
//{
//    int xorV = 0 , n = v.size();
//    for(int i=0;i<n;i++)
//    {
//        xorV ^= v[i];
//    }
//    cout<<xorV<<endl;
//    int temp = xorV, mask =0, i=0;
//    while(temp>0)
//    {
//        if(temp&1)
//        {
//            mask = 1<<i;
//            break;
//        }
//        i++;
//        temp >>= 1;
//    }
//    cout<<mask<<endl;
//    int first =0;
//    for(int i=0;i<n;i++)
//    {
//        if(mask&v[i])
//        {
//            first ^= v[i];
//        }
//
//    }
//    int second = first^xorV;
//    cout<<first<<" "<<second<<endl;
//
//}
//int main()
//{
//   int n;
//   cin>>n;
//   vector<int> v(n);
//   for(int i=0;i<n;i++)
//   {
//       int no;
//       cin>>no;
//       v.push_back(no);
//   }
//   printUnique(v);
//
//
//    return 0;
//}
//
//
//
//
//*
//
//8
//1 2 3 3 2 1 5 6
//3
//1
//3 0
//
//*/
//
//
//


#include<iostream>
#include<vector>
using namespace std;
void printUnique(vector<int> v)
{
	int xorV = 0;
	int n = v.size();
	for(int i=0;i<n;i++)
	{
		xorV ^= v[i];
	}
	int first = 0, second = 0, mask =0, i=0;
	int temp = xorV;
	while(temp>0)
	{
		if(temp&1)
		{
			mask = 1<<i;
			break;
		}
		i++;
		temp >>= 1;
	}
	for(int i=0;i<n;i++)
	{
		if(mask&v[i])
		{
			first ^= v[i];
		}
	}
	second = first^xorV;
	cout<<first<<" "<<second;
}
int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		int no;
		cin>>no;
		v.push_back(no);
	}
	printUnique(v);
	return 0;
}
