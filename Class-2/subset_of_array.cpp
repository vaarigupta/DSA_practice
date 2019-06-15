#include<iostream>
#include<cstring>
using namespace std;
void generateSubset(char input[], int i)
{
   int j=0;
   while(i>0)
   {
       if(i&1)
       {
           cout<<input[j];
       }
       i >>= 1;
       j++;
   }
   cout<<endl;
}
void printSubsets(char input[])
{
    int n = strlen(input);
    for(int i=0;i<(1<<n);i++)
    {
        generateSubset(input,i);
    }

}
int main()
{
    char input[10];
    cout<<"Enter the string : "<<endl;
    cin>>input;
    printSubsets(input);

}
