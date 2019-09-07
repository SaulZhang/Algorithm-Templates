#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
const int N = 500+5;
struct Node{int v,l;};
int n,m,c1,c2,u,v,l,maxNum=0,cnt=0,People[N],dis[N];
bool vis[N];
vector<Node>Vec[N];
vector<int> pre[N],temppath;
void dfs(int x){
    temppath.push_back(x);
    if(x==c1){
        cnt++;
        int sum=0;
        for(int i=0;i<temppath.size();i++) sum+=People[temppath[i]];
        if(sum>maxNum) maxNum=sum;
    }
    for(int i=0;i<pre[x].size();i++)
        dfs(pre[x][i]);
    temppath.pop_back();
}
int main()
{
    cin>>n>>m>>c1>>c2;
    fill(dis,dis+n,INT_MAX);
    fill(vis,vis+n,false);
    for(int i=0;i<n;i++)cin>>People[i];
    for(int i=0;i<m;i++){
        cin>>u>>v>>l;
        Vec[u].push_back(Node{v,l});
        Vec[v].push_back(Node{u,l});
    }
    int newP = c1;
    dis[newP]=0;
    vis[newP]=true;
    int T=n-1;
    while(T--){
        for(int i=0;i<Vec[newP].size();i++){
            int tmpv = Vec[newP][i].v;
            int tmpl = Vec[newP][i].l;
            if(vis[tmpv])continue;
            if(dis[newP]+tmpl<dis[tmpv]){
                dis[tmpv]=dis[newP]+tmpl;
                pre[tmpv].clear();
                pre[tmpv].push_back(newP);
            }
            else if(dis[newP]+tmpl==dis[tmpv]){
                pre[tmpv].push_back(newP);
            }
        }
        int minn = INT_MAX;
        for(int i=0;i<n;i++){
            if(!vis[i]&&dis[i]<minn){
                minn = dis[i];newP = i;
            }
        }
        vis[newP]=true;
    }
    dfs(c2);
    cout<<cnt<<" "<<maxNum<<endl;
    return 0;
}
