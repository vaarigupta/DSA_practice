#include<iostream>
#include<cstring>
using namespace std;
void subsequence(char *input, char *output, int i, int j)
{
    if(input[i]=='\0')
    {
        output[j] = '\0';
        cout<<output<<" ";
        return;
    }
    ///excluding case
    subsequence(input,output,i+1,j);
    ///including case
    output[j] = input[i];
    subsequence(input,output,i+1,j+1);


}
int main() {

    char input[100], output[100];
    cin>>input;
    subsequence(input,output,0,0);
     int len = strlen(input);
    int num_seq = 1<<len;
    cout<<num_seq<<endl;

	return 0;
}
