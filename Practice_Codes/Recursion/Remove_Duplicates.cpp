#include<iostream>
using namespace std;

void Removeduplicates(char *input , char * output , int i, int j)
{
    if(input[i]=='\0')
    {
        output[j] = '\0';
        cout<<output;
        return;
    }
    int prev = i-1;
    int next = i;
    if(input[prev]==input[next])
    {
        Removeduplicates(input,output,i+1,j);
    }

    else
    {
        output[j] = input[i];
        Removeduplicates(input,output,i+1,j+1);
    }
}

int main()
{

   char input[1005], output[1005];
   cin.getline(input,1005);
   Removeduplicates(input,output,0,0);
    return 0;
}







