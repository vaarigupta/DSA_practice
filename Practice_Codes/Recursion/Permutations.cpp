#include<iostream>
#include<cstring>
using namespace std;

void permutation(char *input, int i)
{
    ///InPlace permutation in array - we have not taken any other array - output to store the output
    if(input[i]=='\0')
    {
        cout<<input<<" , ";
        return;
    }
    for(int j=i;input[j]!='\0';j++)
    {
        swap(input[i],input[j]);
        permutation(input,i+1);
        ///Restoration of Array - Backtracking
        swap(input[i],input[j]);
    }

}

int main()
{

   char input[1005];
   cin.getline(input,1005);
   permutation(input,0);
    return 0;
}









