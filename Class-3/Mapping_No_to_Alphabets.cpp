#include<iostream>
using namespace std;
///Make possible strings from given numbers and write only character subsets

void mapping(char *input, char *output, int i , int j)
{

    if(input[i]=='\0')
    {
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }

    int digit = input[i] - '0';
    char ch = digit + 'A' - 1;
    output[j]= ch;
    mapping(input,output,i+1,j+1);
    if(input[i+1]!='\0')
    {
        int secondDigit = input[i+1] - '0';
        int no = digit*10 + secondDigit;
        if(no<=26)
        {
            ch = no + 'A' -1;
            output[j] = ch;
            mapping(input,output,i+2, j+2);
        }
    }





}
int main()
{
char input[100], output[100];
cin>>input;
mapping(input,output,0,0);

    return 0;
}

