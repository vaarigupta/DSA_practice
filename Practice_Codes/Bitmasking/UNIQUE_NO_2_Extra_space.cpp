#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void uniqueNumbers(vector<int> nums)
{
    unordered_set<int> s;
    for(int i=0;i<nums.size();i++)
    {
        if(s.count(nums[i]))
        {
            s.erase(nums[i]);
        }
        else
        {
            s.insert(nums[i]);
        }

    }
    for(auto it = s.begin(); it!=s.end();it++)
    {
        cout<<(*it)<<endl;
    }
    //cout<<*(s.begin())<<" "<<*(s.begin())<<endl;
}
int main()
{

    vector<int> nums = { 1,2,2,3,4,3};
    uniqueNumbers(nums);
    return 0;
}
