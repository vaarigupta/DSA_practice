#include<iostream>
using namespace std;
void lower_upper(char c)
{
    int lower_a = (int)'a';
    int lower_z = (int)'z';
    int upper_a = (int)'A';
    int upper_z = (int)'Z';
    int ans = c -'\0';
    if(lower_a<= ans && ans<=lower_z )
    {
        cout<<"L";
    }
    else if(upper_a<=ans && ans<=upper_z)
    {
        cout<<"U";
    }
    else
    {
        cout<<"I";
    }
}
int main() {
    char c;
    cin>>c;
    lower_upper(c);
    //cout<<c-'\0'<<" "<<(int)'a'<<" "<<(int)'z'<<" "<<(int)'A'<<" "<<(int)'Z';

	return 0;
}
