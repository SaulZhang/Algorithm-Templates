#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1000+10+5;
const int M = 10+5;
const int inf = 99999999;
int edge[N][N],n,m,k,ds,loc,d,dis[M][N],mark[M][N];
string c1,c2;
map<string,int>Name2id;
map<int,string>Id2name;
int main()
{
    cin>>n>>m>>k>>ds;
    loc=n+1;
    for(int i=1;i<=n+m;i++)
        for(int j=1;j<=n+m;j++)
            edge[i][j]=inf;
    for(int i=1;i<=n;i++)
        Name2id[to_string(i)]=i;
    for(int i=1;i<=m;i++){
        Name2id["G"+to_string(i)]=loc;
        Id2name[loc]="G"+to_string(i);
        loc++;
    }
    for(int i=0;i<k;i++){
        cin>>c1>>c2>>d;
        edge[Name2id[c1]][Name2id[c2]] = d;
        edge[Name2id[c2]][Name2id[c1]] = d;
    }
    fill(dis[0],dis[0]+M*N,inf);
    fill(mark[0],mark[0]+M*N,0);
    //做m次Dijkstra
    for(int cnt=1;cnt<=m;cnt++){
        int newP = n+cnt;
        dis[cnt][newP]=0;
        mark[cnt][newP]=1;
        for(int _k=1;_k<n+m;_k++){
            for(int i=1;i<=n+m;i++){
                if(mark[cnt][i]==0){
                    if(dis[cnt][i]>dis[cnt][newP]+edge[newP][i])
                        dis[cnt][i]=dis[cnt][newP]+edge[newP][i];
                }
            }
            int minNum = inf;
            for(int i=1;i<=n+m;i++){
                if(minNum>dis[cnt][i]&&mark[cnt][i]==0){
                    minNum=dis[cnt][i];newP = i;
                }
            }
            mark[cnt][newP] = 1;
        }
    }
    int idx=-1,maxDis=0,minHouseDis=inf,curDis;
    for(int i=1;i<=m;i++){
        int curDis = 0;
        int curHouseDis=0;
        bool flag=true;
        curDis = *min_element(dis[i]+1,dis[i]+n+1);
        for(int j=1;j<=n;j++){
            if(dis[i][j]>ds)
                flag=false;
            curHouseDis+=dis[i][j];
        }
        if(flag&&curDis>maxDis){
            idx = i;
            maxDis = curDis;
            minHouseDis = curHouseDis;
        }
        else if(flag&&curDis==maxDis){
            if(curHouseDis<minHouseDis){
                idx = i;
                maxDis = curDis;
                minHouseDis = curHouseDis;
            }
        }
    }
    if(idx!=-1){
        printf("%s\n",Id2name[idx+n].c_str());
        printf("%.1f %.1f\n",1.0*maxDis,1.0*minHouseDis/n+0.01);
    }
    else{
        cout<<"No Solution"<<endl;
    }
    return 0;
}
/*
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
*/
