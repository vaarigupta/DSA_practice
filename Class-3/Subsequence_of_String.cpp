#include<iostream>
using namespace std;
///Subsequence of given string

void Subsequence(char *input, char *output, int i , int j)
{

    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<endl;

        return;
    }
    output[j] = input[i];
    Subsequence(input,output,i+1,j+1);
    output[j] = '\0';
    Subsequence(input,output,i+1,j);
}
int main()
{

char input[10],output[10];
cin>>input;
Subsequence(input,output,0,0);


    return 0;
}


