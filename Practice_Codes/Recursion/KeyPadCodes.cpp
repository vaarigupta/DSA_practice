#include<iostream>
using namespace std;
char keypad[][10] = {"", "abc","def","ghi","jkl","mno","pqrs","tuv","wx", "yz"};
static int count_no = 0;
void phoneKeyPad(char *input , char * output , int i, int j)
{

    if(input[i]=='\0')
    {
        output[j]='\0';
        count_no++;
        cout<<output<<" ";
        return;
    }
    int index = input[i] - '0';
    if(index == 0)
    {
        phoneKeyPad(input,output,i+1,j);
    }
    for(int k=0;keypad[index][k]!='\0';k++)
    {
        output[j] = keypad[index][k];
        phoneKeyPad(input,output,i+1,j+1);
    }

}
int count_Words()
{
    return count_no;
}
int main()
{

   char input[100], output[100];
   cin.getline(input,100);
   phoneKeyPad(input,output,0,0);
   cout<<endl<<count_Words()<<endl;
    return 0;
}





