#include<iostream>
using namespace std;
int main()
{
    float p, num=365, denom=365.0, currenProb=(num/denom);
    int peop=0;
    cin>>p;

    while(currenProb>=(1-p))
    {
      currenProb*= (num/denom);
      num--;
      peop++;
      cout<<currenProb<<" for "<<peop<<" people"<<endl;

    }
    cout<<"No of people in the hall : "<<peop<<endl;


    return 0;
}
