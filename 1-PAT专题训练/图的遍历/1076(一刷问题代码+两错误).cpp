/*
图的dfs问题，有两格case没有过
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1000+5;
vector<int> Vec[N];
int n,l,k,mark[N],pa,ans=0,m,x;
void dfs(int x,int dep){
    if(dep>l)
        return;
    cout<<"find :"<<x<<endl;
    ans++;
    mark[x]=1;
    for(int i=0;i<Vec[x].size();i++){
        if(mark[Vec[x][i]]==0)
            dfs(Vec[x][i],dep+1);
    }
}
int main()
{
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>pa;
            Vec[pa].push_back(i);
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>x;
        fill(mark+1,mark+1+n,0);
        ans=0;
        dfs(x,0);
        cout<<ans-1<<endl;
    }
    return 0;
}
/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
*/
