#include <iostream>
#include <cmath>
#include <climits>
#include <map>
using namespace std;
const int N = int(sqrt(INT_MAX))+1;
int loc=0,prime[N],n,n_t;
bool vis[N];
map<int,int>Ma;
void init(){//素数筛
    for(int i=2;i<N;i++){
        if(!vis[i]){
            prime[loc++]=i;
            for(int j=i;j<N;j+=i){
                vis[j]=true;
            }
        }
    }
}
bool isPrime(int x){
    int up=int(sqrt(x))+1;
    for(int i=2;i<=up;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
int main()
{
    init();
    cin>>n;
    n_t=n;
    if(isPrime(n)){
        cout<<n_t<<"="<<n<<endl;
    }
    else{
        int pos=0;
        while(pos<loc){
            while(n%prime[pos]==0){
                Ma[prime[pos]]++;
                n/=prime[pos];
            }
            pos++;
        }
        int num = Ma.size(),cnt=0;
        cout<<n_t<<"=";
        for(auto it=Ma.begin();it!=Ma.end();it++){
            cnt++;
            if(it->second==1){
                cout<<it->first;
            }
            else{
                cout<<it->first<<"^"<<it->second;
            }
            if(cnt!=num)
                cout<<"*";
        }
    }
    return 0;
}
