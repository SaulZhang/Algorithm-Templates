#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e4+5;
int Hash[N];
int n,Msize,x;
bool isPrime(int x){
    if(Msize<=1)return false;
    int up=int(sqrt(x))+1;
    for(int i=2;i<up;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    cin>>Msize>>n;//注意Msize可能取到1
    while(!isPrime(Msize))Msize++;
    for(int i=0;i<n;i++){
        cin>>x;
        int c=0;
        bool flag=false;
        while(c<=Msize-1){
            int newx = x+c*c;
            if(Hash[newx%Msize]==0){
                Hash[newx%Msize]=x;
                cout<<newx%Msize;
                flag=true;
                break;
            }
            else
                c++;
        }
        if(!flag) cout<<"-";
        if(i!=n-1) cout<<" ";
    }
    return 0;
}
