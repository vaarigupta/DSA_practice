//#include<iostream>
//#include<cstring>
//using namespace std;
//int strToNum(char *a, int n)
//{
//    if(n==0)
//    {
//        return 0;
//    }
//
//    int last_digit = a[n-1] - '0';
//    int chotaInt = strToNum(a,n-1);
//
//    return chotaInt*10 + last_digit;
//
//}
//int main()
//{
//    char input[] = "1234";
//    int len = strlen(input);
//    cout<<strToNum(input,len)<<endl;
//
//    return 0;
//}
//
//


#include<iostream>
#include<cstring>
using namespace std;
int strToInt(char *a, int n)
{
    if(n==0)
    {
        return 0;
    }

    int last_digit = a[n-1] - '0';
    int chotInt = strToInt(a,n-1);

    return chotInt*10 + last_digit;
}
int main() {
    char input[30];
    cin>>input;
    int ans = strToInt(input,strlen(input));
    cout<<ans;

	return 0;
}
