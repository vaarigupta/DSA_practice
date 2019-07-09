#include<iostream>
#include<cstring>
using namespace std;
void canYouRead(char *a)
{
    int n = strlen(a),temp;
    int upper_a = (int)'A';
    int upper_z = (int)'Z';
    for(int i=0;i<n;i++)
    {
        temp = a[i] - '\0';
        if(upper_a<=a[i] && a[i]<=upper_z)
        {
            cout<<endl;
        }
        cout<<a[i];

    }

}
int main()
{
     char a[1000];
    cin.getline(a,1000);
    canYouRead(a);

    return 0;
}

