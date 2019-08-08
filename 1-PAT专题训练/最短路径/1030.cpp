#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 500+5;
const int inf = 99999999;

struct Edge{
    int v;
    int l;
    int c;
    Edge(int _v,int _l,int _c){
        v = _v;
        l = _l;
        c = _c;
    }
};

int dis[N];
int cost[N];

bool mark[N];
int n,m,st,ed;
int pre[N];

vector<Edge>Vec[N];

int main()
{

    cin>>n>>m>>st>>ed;
    fill(dis,dis+n,inf);
    fill(cost,cost+n,0);
    fill(pre,pre+n,0);
    int c1,c2,len,pri;
    for(int i=0;i<m;i++){
        cin>>c1>>c2>>len>>pri;
        Vec[c1].push_back(Edge(c2,len,pri));
        Vec[c2].push_back(Edge(c1,len,pri));
    }

    int newP = st;
    dis[newP] = 0;
    cost[newP] = 0;
    mark[newP] = true;

    for(int k=0;k<n-1;k++){

        for(int i=0;i<int(Vec[newP].size());i++){
            int tmp_v = Vec[newP][i].v;
            int tmp_l = Vec[newP][i].l;
            int tmp_c = Vec[newP][i].c;
            if(!mark[tmp_v]){
                if(dis[tmp_v]>dis[newP]+tmp_l){
                    dis[tmp_v] = dis[newP]+tmp_l;
                    cost[tmp_v] = cost[newP]+tmp_c;
                    pre[tmp_v]=newP;
                }
                else if(dis[tmp_v]==dis[newP]+tmp_l){
                    if(cost[tmp_v]>cost[newP]+tmp_c){
                        cost[tmp_v] = cost[newP]+tmp_c;
                        pre[tmp_v]=newP;
                    }
                }

            }
        }
        int minn = inf;
        for(int i=0;i<n;i++){
            if(!mark[i]&&dis[i]<minn){
                minn = i;
                newP = i;
            }
        }
        mark[newP]=true;
    }
    int tmp[n];
    int cnt=0;
    int x = ed;
    while(x!=st){
        tmp[cnt++]=x;
        x = pre[x];
    }
    tmp[cnt++]=st;
    for(int i=cnt-1;i>=0;i--){
        cout<<tmp[i]<<" ";
    }
    cout<<dis[ed]<<" "<<cost[ed]<<endl;
    return 0;
}
/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/
