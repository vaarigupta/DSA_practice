#include <iostream>
using namespace std;
int pp[1000000];

void sieve(){
    for(int i=2;i*i<=1000000;i++){
        if(pp[i]){
            for(int j=2*i;j<1000000;j+=i)
                pp[j]=0;



        }
    }
}

int main() {
    int i,j,n,a,p=0,t;
cin>>t;
fill(pp,pp+1000000,1);
sieve();
int ans[1000000];
int k=0;
for(int i=2;i<1000000;i++){
    if(pp[i])
    ans[k++]=i;
}
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n-1]<<endl;
    }
}

