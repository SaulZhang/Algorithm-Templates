/*
    第一遍的做题思路：因为如果只考虑到要保证minTack最小的话，这样在求解的过程中是
    最优最优子结构的。

    （ If there are more than one shortest path, the one that requires
       the least number of bikes sent from PBMC will be chosen.）
    (Note that if such a path is not unique, output the one that requires
     minimum number of bikes that we must take back to PBMC.
     The judge's data guarantee that such a path is unique.)
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int N = 500 + 5;
const int inf = 99999999;

struct Edge{
    int v;
    int cost;
    Edge(int _v,int _cost){
        v = _v;
        cost = _cost;
    }
};

int dis[N];
int Num_Bike[N];
bool mark[N];
int cap,n,st=0,ed,m;
vector<int> pre[N],path,temppath;
vector<Edge> Vec[N];

int NumTake = inf;
int NumBack = 0;

void dfs(int x){

    temppath.push_back(x);

    if(x==0){
        int Take=0,Back=0;

        for(int i=0;i<temppath.size()-1;i++){
            Take +=(cap/2-Num_Bike[temppath[i]]);
        }

        if(Take<0)
            Back = -Take,Take=0;

        if(Take<NumTake){
            NumTake = Take;
            NumBack = Back;
            path = temppath;
        }
        else if(Take==NumTake&&Back<NumBack){
            NumBack = Back;
            path = temppath;
        }
    }

    for(int i=0;i<pre[x].size();i++){
        dfs(pre[x][i]);
    }


    temppath.pop_back();
}

int main()
{
    cin>>cap>>n>>ed>>m;
    for(int i=1;i<=n;i++)
        cin>>Num_Bike[i];
    int u,v,c;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>c;
        Vec[u].push_back(Edge(v,c));
        Vec[v].push_back(Edge(u,c));
    }

    for(int i=0;i<=n;i++)
        dis[i]=INT_MAX,mark[i]=false;

    int newP=0;
    dis[newP]=0;
    mark[newP]=true;

    for(int k=1;k<=n;k++){
        for(int i=0;i<Vec[newP].size();i++){
            int tmp_v = Vec[newP][i].v;
            int tmp_cost = Vec[newP][i].cost;
            if(!mark[tmp_v]){
                if(dis[newP]+tmp_cost<dis[tmp_v]){
                    dis[tmp_v]=dis[newP]+tmp_cost;
                    pre[tmp_v].clear();
                    pre[tmp_v].push_back(newP);
                }
                else if(dis[newP]+tmp_cost==dis[tmp_v]){
                    pre[tmp_v].push_back(newP);
                }
            }
        }
        int Min = INT_MAX;
        for(int i=1;i<=n;i++){
            if(!mark[i]&&Min>dis[i]){
                Min = dis[i];
                newP = i;
            }
        }
        mark[newP]=true;
    }

    dfs(ed);
    cout<<NumTake<<" ";
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i];
        if(i!=0)
            cout<<"->";
        else
            cout<<" ";
    }
    cout<<NumBack<<endl;
    return 0;
}
