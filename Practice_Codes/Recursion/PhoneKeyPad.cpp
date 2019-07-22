#include<iostream>
using namespace std;
char keypad[][10] = {"", "", "ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void phoneKeyPad(char *input , char * output , int i, int j)
{

    ///Base Case
    if(input[i]=='\0')
    {
        output[j] = '\0';
        cout<<output<<endl;
        return;///very important to write - to make it a base case and return ans to the next call
    }

    ///Rec Case
    int digit = input[i] - '0';
    if(digit==0 || digit==1)
    {
        phoneKeyPad(input,output,i+1,j);
    }
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
        output[j] = keypad[digit][k];
        phoneKeyPad(input,output,i+1,j+1);
    }

}
int main()
{

   char input[100], output[100];
   cin.getline(input,100);
   phoneKeyPad(input,output,0,0);
    return 0;
}



