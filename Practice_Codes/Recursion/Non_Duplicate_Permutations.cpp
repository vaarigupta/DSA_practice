#include<iostream>
#include<cstring>
#include<set>
using namespace std;

void permutation(char *input, int i, set<string> &s)
{
   if(input[i]=='\0')
   {
       string temp = input;
       s.insert(temp);
       return;
   }

   for(int j=i;input[j]!='\0';j++)
   {
       swap(input[j],input[i]);
       permutation(input,i+1,s);
       swap(input[j],input[i]);
   }
}

int main()
{
    set<string> s;
   char input[1005];
   cin.getline(input,1005);
   permutation(input,0,s);
   for(auto t:s)
   {
       cout<<t<<endl;
   }
    return 0;
}










