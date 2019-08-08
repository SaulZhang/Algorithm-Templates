#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int N = 200+5;
const int inf = 99999999;

unordered_map<string,int> City_happiness;
unordered_map<string,int> City_no;
unordered_map<int,string> No_City;

struct Edge{
    int v;
    int c;
    Edge(int _v,int _c){
        v = _v;
        c = _c;
    }
};

int n,m,st,ed;
int loc=0;
string start;
string city,city1,city2;
int hap,cost;
int dis[N];
bool mark[N];
vector<Edge> Vec[N];
vector<int> pre[N],path,tmppath;
int totnum=0;
int Max_happiness = -inf;
int avg_happiness;

void dfs(int x){
    tmppath.push_back(x);
    if(x==st){
        totnum++;
        int tothap=0;
        for(int i=0;i<tmppath.size();i++){
            int id = tmppath[i];
            tothap += City_happiness[No_City[id]];
        }
        if(tothap>Max_happiness){
            Max_happiness = tothap;
            path = tmppath;
            avg_happiness = int(tothap/(tmppath.size()-1));
        }
        else if(tothap==Max_happiness&&avg_happiness<int(tothap/(tmppath.size()-1))){
            path = tmppath;
            avg_happiness = int(tothap/(tmppath.size()-1));
        }

    }
    for(int i=0;i<pre[x].size();i++)
        dfs(pre[x][i]);

    tmppath.pop_back();
}

int main()
{
    fill(dis,dis+N,inf);
    cin>>n>>m>>start;

    City_no[start]=loc;
    No_City[loc] = start;
    loc++;

    for(int i=0;i<n-1;i++){
        cin>>city>>hap;
        City_happiness[city]=hap;
        if(City_no.count(city)==0){
            City_no[city]= loc;
            No_City[loc] = city;
            loc++;

        }
    }

    st = City_no[start];
    ed = City_no["ROM"];

    for(int i=0;i<m;i++){
        cin>>city1>>city2>>cost;
        Vec[City_no[city1]].push_back(Edge(City_no[city2],cost));
        Vec[City_no[city2]].push_back(Edge(City_no[city1],cost));
    }

    int newP = st;
    dis[newP] = 0;
    mark[newP] = true;

    for(int k=0;k<n-1;k++){
        for(int i=0;i<int(Vec[newP].size());i++){
            int tmp_v = Vec[newP][i].v;
            int tmp_c = Vec[newP][i].c;
            if(!mark[tmp_v]){
                if(dis[tmp_v]>dis[newP]+tmp_c){
                    dis[tmp_v]=dis[newP]+tmp_c;
                    pre[tmp_v].clear();
                    pre[tmp_v].push_back(newP);
                }
                else if(dis[tmp_v]==dis[newP]+tmp_c){
                    pre[tmp_v].push_back(newP);
                }
            }
        }
        int minn = inf;
        for(int i=0;i<n;i++){
            if(!mark[i]&&dis[i]<minn){
                minn = dis[i];
                newP = i;
            }
        }
        mark[newP]=true;
    }

    dfs(ed);

    cout<<totnum<<" "<<dis[ed]<<" "<<Max_happiness<<" "<<avg_happiness<<endl;
    for(int i=path.size()-1;i>=0;i--){
        cout<<No_City[path[i]];
        if(i!=0)
            cout<<"->";
        else
            cout<<endl;
    }


    return 0;
}

/*
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
*/
