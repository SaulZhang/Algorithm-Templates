#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 100+5;
int state[N],n,tmp[2],A[N];
vector<int> liar;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>A[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            fill(state,state+N,1);
            liar.clear();
            state[i]=-1;
            state[j]=-1;
            for(int k=1;k<=n;k++){
                if(state[abs(A[k])]*A[k]<0)liar.push_back(k);
            }
            if(liar.size()==2&&state[liar[0]]+state[liar[1]]==0){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    cout<<"No Solution"<<endl;

    return 0;
}
