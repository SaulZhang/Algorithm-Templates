#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 500+5;
const int inf = 99999999;
struct Next{
    int no,len,tim;
};
int n,m,v1,v2,one_way,len,tim,st,ed;
int dis[N],Tim[N],minTimCost=inf;
bool markDis[N]={false},markTim[N]={false};
vector<Next> Vec[N];
vector<int> pre[N],tmppath,resDis,resTim;
void dijkstraDis(int n){
    int newP=st;
    markDis[newP]=true;
    dis[newP]=0;
    int T=n;
    while(T--){
        for(int i=0;i<Vec[newP].size();i++){
            int v = Vec[newP][i].no;
            int tmpL = Vec[newP][i].len;
            if(markDis[v])continue;
            if(dis[v]>dis[newP]+tmpL){
                dis[v] = dis[newP]+tmpL;
                pre[v].clear();
                pre[v].push_back(newP);
//                cout<<newP<<"->"<<v<<endl;
            }
            else if(dis[v]==dis[newP]+tmpL){
                pre[v].push_back(newP);
//                cout<<newP<<"->"<<v<<endl;
            }
        }
        int minn = inf;
        for(int i=0;i<n;i++){
            if(!markDis[i]&&dis[i]<minn){
                newP = i;minn = dis[i];
            }
        }
//        for(int i=0;i<n;i++)
//            cout<<dis[i]<<" ";
//        cout<<endl;
//        cout<<"choose:"<<newP<<" ";
        markDis[newP]=true;
    }
}

void dijkstraTim(int n){
    int newP=st;
    markTim[newP]=true;
    Tim[newP]=0;
    int T=n;
    while(T--){
        for(int i=0;i<Vec[newP].size();i++){
            int v = Vec[newP][i].no;
            int tmpT = Vec[newP][i].tim;
            if(Tim[v]>Tim[newP]+tmpT){
                Tim[v] = Tim[newP]+tmpT;
                pre[v].clear();
                pre[v].push_back(newP);
            }
            else if(Tim[v]==Tim[newP]+tmpT){
                pre[v].push_back(newP);
            }
        }
        int minn = inf;
        for(int i=0;i<n;i++){
            if(!markTim[i]&&Tim[i]<minn){
                newP = i;minn = Tim[i];
            }
        }
        markTim[newP]=true;
    }
}

void dfsDis(int n){
    tmppath.push_back(n);
    if(n==st){//找到一条路径
        int timcost=0;
        for(int i=tmppath.size()-1;i>=1;i--){
            for(int j=0;j<Vec[tmppath[i]].size();j++){
                if(Vec[tmppath[i]][j].no==tmppath[i-1]){
                    timcost+=Vec[tmppath[i]][j].tim;
                    break;
                }
            }
        }
        if(timcost<minTimCost){
            minTimCost=timcost;resDis=tmppath;
        }
        else if(timcost==minTimCost){
            if(resDis.size()>tmppath.size()) resDis=tmppath;
        }
    }
    for(int i=0;i<pre[n].size();i++)
        dfsDis(pre[n][i]);
    tmppath.pop_back();
}

void dfsTim(int n){
    tmppath.push_back(n);
    if(n==st){//找到一条路径
        //calculate the time cost.
        if(resTim.size()==0||resTim.size()>tmppath.size())
            resTim=tmppath;
    }
    for(int i=0;i<pre[n].size();i++)
        dfsTim(pre[n][i]);
    tmppath.pop_back();
}


bool check(){
    if(resDis.size()!=resTim.size())
        return false;
    for(int i=0;i<resTim.size();i++){
        if(resDis[i]!=resTim[i])
            return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>one_way>>len>>tim;
        Vec[v1].push_back(Next{v2,len,tim});
        if(one_way==0)
            Vec[v2].push_back(Next{v1,len,tim});
    }
    cin>>st>>ed;
    fill(dis,dis+N,inf);
    fill(Tim,Tim+N,inf);
    dijkstraDis(n);
    dfsDis(ed);
    dijkstraTim(n);
    dfsTim(ed);
    if(!check()){
        cout<<"Distance = "<<dis[ed]<<": ";
        for(int i=resDis.size()-1;i>=0;i--){
            if(i==resDis.size()-1)
                cout<<resDis[i];
            else
                cout<<" -> "<<resDis[i];
        }
        cout<<endl;
        cout<<"Time = "<<Tim[ed]<<": ";
        for(int i=resTim.size()-1;i>=0;i--){
            if(i==resTim.size()-1)
                cout<<resTim[i];
            else
                cout<<" -> "<<resTim[i];
        }
        cout<<endl;
    }
    else{
        cout<<"Distance = "<<dis[ed]<<"; Time = "<<Tim[ed]<<": ";
        for(int i=resDis.size()-1;i>=0;i--){
            if(i==resDis.size()-1)
                cout<<resDis[i];
            else
                cout<<" -> "<<resDis[i];
        }
        cout<<endl;
    }

    return 0;
}
