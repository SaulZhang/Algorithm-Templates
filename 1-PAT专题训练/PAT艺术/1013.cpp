#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3+5;
int n,m,k,c1,c2,c;
vector<int>Vec[N];
bool Vis[N];
void dfs(int x,int y){
    Vis[x]=true;
    for(int i=0;i<Vec[x].size();i++){
        if(!Vis[Vec[x][i]]&&Vec[x][i]!=y) dfs(Vec[x][i],y);
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>c1>>c2;
        Vec[c1].push_back(c2);
        Vec[c2].push_back(c1);
    }
    while(k--){
        cin>>c;
        fill(Vis,Vis+n+1,false);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i!=c&&!Vis[i]){
                cnt++; dfs(i,c);
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
