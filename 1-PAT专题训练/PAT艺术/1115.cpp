#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+5;
int n,A[N],maxDep=0;
vector<int>Vec[N];
int Cnt[N];
void Insert(int root,int x){
    if(A[x]<=A[root]){
        if(Vec[root][0]==-1) Vec[root][0]=x;
        else Insert(Vec[root][0],x);
    }
    else{
        if(Vec[root][1]==-1) Vec[root][1]=x;
        else Insert(Vec[root][1],x);
    }
}
void dfs(int x,int dep){
    Cnt[dep]++;
    maxDep=max(maxDep,dep);
    for(int i=0;i<2;i++)
        if(Vec[x][i]!=-1) dfs(Vec[x][i],dep+1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
    for(int i=0;i<n;i++)Vec[i].resize(2,-1);
    for(int i=1;i<n;i++)Insert(0,i);
    dfs(0,1);
    cout<<Cnt[maxDep]<<" + "<<Cnt[maxDep-1]<<" = "<<Cnt[maxDep]+Cnt[maxDep-1]<<endl;
    return 0;
}
