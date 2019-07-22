#include<iostream>
using namespace std;
void subsequences(char *input , char * output , int i, int j)
{
    ///Base Case
    if(input[i]=='\0')
    {
        output[j] = '\0';
        cout<<output<<endl;
        return;///very important to write - to make it a base case and return ans to the next call
    }
    ///Rec Case

    ///Include character
    output[j] = input[i];
    subsequences(input,output,i+1,j+1);
    ///Exclude character
    subsequences(input,output,i+1,j);
}
int main()
{

   char input[100], output[100];
   cin.getline(input,100);
   subsequences(input,output,0,0);
    return 0;
}


