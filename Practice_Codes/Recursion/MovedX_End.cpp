#include<iostream>
#include<cstring>
using namespace std;

void moveX(char *input , char * output ,int n, int i, int j)
{
    if(input[i]=='\0')
    {
        while(j<n)
        {
            output[j]='x';
            j++;
        }
        output[j]='\0';
        cout<<output<<" ";
        return;
    }
    if(input[i]=='x')
    {
        moveX(input,output,n,i+1,j);
    }
    else
    {
        output[j] = input[i];
        moveX(input,output,n,i+1,j+1);
    }
}

int main()
{

   char input[1005], output[1005];
   cin.getline(input,1005);
   int len = strlen(input);
   moveX(input,output,len,0,0);
    return 0;
}








