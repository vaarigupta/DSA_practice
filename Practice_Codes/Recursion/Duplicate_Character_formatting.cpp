#include<iostream>
using namespace std;

void duplicates(char *input , char * output , int i, int j)
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
        char d = input[i];
        output[j]= '*';
        output[j+1]= d;
        duplicates(input,output,i+1,j+2);
    }
    else
    {
    output[j] = input[i];
    duplicates(input,output,i+1,j+1);
    }

}

int main()
{

   char input[100], output[100];
   cin.getline(input,100);
   duplicates(input,output,0,0);
    return 0;
}






