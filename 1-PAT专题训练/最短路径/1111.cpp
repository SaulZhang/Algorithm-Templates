/*

还有两个case暂时没过
如果要维护最短路径的结点数量也可以在用一个数组来维护num[tmp_v]=num[newP]+1

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500+5;
const int inf = 99999999;

struct Edge{
    int v;
    int l;
    int t;
    Edge(int _v,int _l,int _t){
        v = _v;
        l = _l;
        t = _t;
    }
};

vector<Edge> Vec[N];
vector<int> pre_T[N],tmppath,path;

int dis[N];
int Cur_tim[N];
int Tim[N];

int mark_D[N];
int mark_T[N];
int pre_D[N];
int n,m;
int c1,c2,one,l,t;
int st,ed;
int minNum=inf;

void dfs(int x){
    tmppath.push_back(x);
    if(x==st){
        if(tmppath.size()<minNum){
            minNum = int(tmppath.size());
            path = tmppath;
        }
    }

    for(int i=0;i<pre_T[x].size();i++)
        dfs(pre_T[x][i]);

    tmppath.pop_back();
}

int main()
{

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>c1>>c2>>one>>l>>t;
        if(one==1){
            Vec[c1].push_back(Edge(c2,l,t));
        }
        else{
            Vec[c1].push_back(Edge(c2,l,t));
            Vec[c2].push_back(Edge(c1,l,t));
        }
    }
    cin>>st>>ed;
    fill(dis,dis+n,inf);
    fill(Tim,Tim+n,inf);

    //Dijkstra for distance

    int newP = st;
    dis[newP] = 0;
    mark_D[newP]  = true;
    Cur_tim[newP] = 0;
    for(int k=0;k<n-1;k++){
        for(int i=0;i<Vec[newP].size();i++){
            int tmp_v = Vec[newP][i].v;
            int tmp_l = Vec[newP][i].l;
            int tmp_t = Vec[newP][i].t;
            if(!mark_D[tmp_v]){
                if(dis[tmp_v]>dis[newP]+tmp_l){
                    dis[tmp_v]=dis[newP]+tmp_l;
                    Cur_tim[tmp_v] = Cur_tim[newP]+tmp_t;
                    pre_D[tmp_v] = newP;
                }
                else if(dis[tmp_v]==dis[newP]+tmp_l){
                    if(Cur_tim[tmp_v] > Cur_tim[newP]+tmp_t){
                        Cur_tim[tmp_v] = Cur_tim[newP]+tmp_t;
                        pre_D[tmp_v] = newP;
                    }
                }

            }
        }
        int minn = inf;
        for(int i=0;i<n;i++){
            if(!mark_D[i]&&dis[i]<minn){
                minn = dis[i];
                newP = i;
            }
        }
        mark_D[newP]=true;
    }

    //Dijkstra for time
    newP = st;
    Tim[newP] = 0;
    mark_T[newP]  = true;
    for(int k=0;k<n-1;k++){
        for(int i=0;i<Vec[newP].size();i++){
            int tmp_v = Vec[newP][i].v;
            int tmp_l = Vec[newP][i].l;
            int tmp_t = Vec[newP][i].t;
            if(!mark_T[tmp_v]){
                if(Tim[tmp_v]>Tim[newP]+tmp_t){
                    Tim[tmp_v]=Tim[newP]+tmp_t;
                    pre_T[tmp_v].clear();
                    pre_T[tmp_v].push_back(newP);
                }
                else if(Tim[tmp_v]==Tim[newP]+tmp_t){
                    pre_T[tmp_v].push_back(newP);
                }
            }
        }
        int minn = inf;
        for(int i=0;i<n;i++){
            if(!mark_T[i]&&Tim[i]<minn){
                minn = Tim[i];
                newP = i;
            }
        }
        mark_T[newP]=true;
    }


    //处理输出的答案
    int tmpD[n];
    int cnt1=0;
    int x = ed;
    while(x!=st){
        tmpD[cnt1++]=x;
        x = pre_D[x];
    }
    tmpD[cnt1++]=st;

    dfs(ed);
    int tmpT[n];
    int cnt2=0;
    for(int i=0;i<path.size();i++){
        tmpT[cnt2++] = path[i];
    }

    bool flag = true;
    if(cnt1!=cnt2){
        cout<<"Distance = "<<dis[ed]<<": ";
        for(int i=cnt1-1;i>=0;i--){
            cout<<tmpD[i];
            if(i!=0)
                cout<<" -> ";
            else
                cout<<endl;
        }

        cout<<"Time = "<<Tim[ed]<<": ";
        for(int i=cnt2-1;i>=0;i--){
            cout<<tmpT[i];
            if(i!=0)
                cout<<" -> ";
            else
                cout<<endl;
        }
    }
    else{
        for(int i=0;i<cnt1;i++){
            if(tmpT[i]!=tmpD[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"Distance = "<<dis[ed]<<"; Time = "<<Tim[ed]<<": "<<Tim[ed]<<": ";
            for(int i=cnt1-1;i>=0;i--){
                cout<<tmpT[i];
                if(i!=0)
                    cout<<" -> ";
                else
                    cout<<endl;
            }
        }
        else{
            cout<<"Distance = "<<dis[ed]<<": ";
            for(int i=cnt1-1;i>=0;i--){
                cout<<tmpD[i];
                if(i!=0)
                    cout<<" -> ";
                else
                    cout<<endl;
            }

            cout<<"Time = "<<Tim[ed]<<": ";
            for(int i=cnt2-1;i>=0;i--){
                cout<<tmpT[i];
                if(i!=0)
                    cout<<" -> ";
                else
                    cout<<endl;
            }
        }


    }

    return 0;
}
/*
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
*/
