#include<iostream>
using namespace std;
class comp
{
    int real;
    int img;
public:
    comp()
    {
        real=0;
        img=0;
    }
    comp(int r, int i)
    {
        real = r;
        img =i;
    }
    void input()
    {
        cout<<"Enter the real and imaginary no :"<<endl;
        cin>>real>>img;
    }
    void print()
    {
        cout<<real<<" + "<<img<<"j"<<endl;
    }
    comp operator + (comp c)
    {
        comp temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    comp operator * (comp c)
    {
        comp temp;
        temp.real = real*(c.real);
        temp.img = img*(c.img);
        return temp;
    }
    void operator !()
{
    this->img = (-1)*(this->img);
}
};
istream & operator>>(istream &is, comp &c)
{
    c.input();
    return is;

}
ostream & operator<<(ostream &os, comp &c)
{
    c.print();
    return os;

}
int main()
{
    comp c1,c2,c3;
    cin>>c2>>c3;
    c1 = c2 + c3;
    cout<<c1;
    !c1;
    cout<<c1;
    return 0;
}
