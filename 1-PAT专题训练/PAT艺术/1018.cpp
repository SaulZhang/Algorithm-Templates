#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int N = 500+5;
struct Node{int v,t;};
int cmax,n,sp,m,minTack=INT_MAX,minBack=INT_MAX,u,v,t,Cap[N],dis[N];
bool vis[N];
vector<Node> Vec[N];
vector<int> pre[N],tmppath,res;
void dfs(int x){
    tmppath.push_back(x);
    if(x==0){
        int curSum=0,curTake=0,curBack=0;
        for(int i=tmppath.size()-1;i>=0;i--) {//记住必须是按顺序去求解minTack和minBack
            int id=tmppath[i];//因为就算路径末端有多余的车辆那也不可能带给前方缺车的地方，只能带回去了
            if(id==0)continue;
            if((Cap[id]-cmax/2)>0) {
                curBack+=(Cap[id]-cmax/2);
            }else{
                if(curBack>(0-(Cap[id]-cmax/2))){
                    curBack+=(Cap[id]-cmax/2);
                }else{
                    curTake+=(0-(Cap[id]-cmax/2))-curBack;
                    curBack = 0;
                }
            }
        }
        if(curTake<minTack){
            minTack=curTake;
            minBack=curBack;
            res=tmppath;
        }
        else if(curTake==minTack&&curBack<minBack){
            minBack=curBack;
            res=tmppath;
        }
    }
    for(int i=0;i<pre[x].size();i++){
        dfs(pre[x][i]);
    }
    tmppath.pop_back();
}
int main()
{
    cin>>cmax>>n>>sp>>m;
    fill(dis,dis+n+1,INT_MAX);
    for(int i=1;i<=n;i++)cin>>Cap[i];
    for(int i=0;i<m;i++){
        cin>>u>>v>>t;
        Vec[u].push_back(Node{v,t});
        Vec[v].push_back(Node{u,t});
    }
    int T=n;
    int newP = 0;
    dis[newP] = 0;
    vis[newP] = true;
    while(T--){
        for(int i=0;i<Vec[newP].size();i++){
            int tmpv=Vec[newP][i].v;
            int tmpt=Vec[newP][i].t;
            if(vis[tmpv])continue;
            if(dis[newP]+tmpt<dis[tmpv]){
                dis[tmpv] = dis[newP]+tmpt;
                pre[tmpv].clear();
                pre[tmpv].push_back(newP);
            }
            else if(dis[newP]+tmpt==dis[tmpv]){
                pre[tmpv].push_back(newP);
            }
        }
        int minn = INT_MAX;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&dis[i]<minn){
                minn = dis[i];newP = i;
            }
        }
        vis[newP]=true;
    }
    dfs(sp);
    reverse(res.begin(),res.end());
    cout<<minTack<<" ";
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1)cout<<"->";
    }
    cout<<" "<<minBack;
    return 0;
}
