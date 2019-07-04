#include<iostream>
using namespace std;
///Tower of Hanoi
void tower_of_hanoi(int n, char src, char helper, char dest)
{
    if(n==0)
    {
        return;
    }
    tower_of_hanoi(n-1,src,dest, helper);
    cout<<"Move "<<n<<" disk from "<<src<<" to "<<dest<<endl;
    tower_of_hanoi(n-1,helper,src, dest);
}

int steps(int n)
{
    if(n==0)
    {
        return 0;
    }

    return steps(n-1) + 1 + steps(n-1);
}
int main()
{
    int n;
    cin>>n;
    tower_of_hanoi(n,'A','B','C');
    cout<<steps(3);

    return 0;
}
