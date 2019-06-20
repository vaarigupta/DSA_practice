#include<iostream>
#include<cstring>
using namespace std;
///Phone Key Pad

char mapping[][10]= {"","","ABC", "DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void phonekeyPad(char *input, char *output,int i, int j)
{
        if(input[i]=='\0')
        {
            output[i] = '\0';
            cout<<output<<endl;
            return;
        }

        //rec case

        int digit = input[i] - '0';
        for(int k=0;k<strlen(mapping[digit]);k++)
        {
            char ch = mapping[digit][k];
            output[j] =ch;
            phonekeyPad(input,output,i+1,j+1);
        }

}
int main()
{
    char input[10];
    char output[10];
    cin>>input;
    phonekeyPad(input,output,0,0);
    return 0;
}

//    char x[] = {"ABC", "DEF", "GHI", "JKL", "MNO" , "PQRS", "TUV" , "WXYZ"};
//    if(input[i]=='\0')
//    {
//        output[j] = '\0';
//        cout<<output;
//    }
//    cnt = i + 2;
//    if(input[i]== )
//    {
//        x[i][0];
//    }
