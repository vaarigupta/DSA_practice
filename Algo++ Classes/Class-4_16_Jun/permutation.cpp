#include<iostream>
using namespace std;

void permut( char input[],int i )
{
    if(input[i]=='\0')
    {
        cout<<input<<endl;
        return;
    }

    for(int j=i;input[j]!='\0';j++)
    {
        swap(input[i],input[j]);
        permut(input,i+1);
        swap(input[i],input[j]);///to restore the array
    }

}
int main()
{
    char input[10];
    cin>>input;
    cout<<"Permutations : "<<endl;
    permut(input,0);
    return 0;
}
