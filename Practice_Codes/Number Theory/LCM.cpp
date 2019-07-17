//#include<iostream>
//using namespace std;
//int GCD(int a,int b)
//{
//    if(b==0)
//    {
//        return a;
//    }
//    return GCD(b,a%b);
//}
//
//int LCM(int a, int b)
//{
//    int gcd = GCD(a,b);
//    return (a*b)/gcd;
//}
//int main()
//{
//    int a,b;
//    cin>>a>>b;
//    cout<<"GCD of "<<a<<" and "<<b<<" : "<<GCD(a,b)<<endl;
//    cout<<"LCM of "<<a<<" and "<<b<<" : "<<LCM(a,b);
//    return 0;
//}
//


#include<iostream>
#define l long int
using namespace std;
 l gcd(l a, l b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b,a%b);

}

l lcm(l a, l b)
{
    l gcd1 = gcd(a,b);
    return (a*b)/gcd1;
}
int main() {
    l n1, n2;
    cin>>n1>>n2;
    cout<<lcm(n1,n2);
	return 0;
}
