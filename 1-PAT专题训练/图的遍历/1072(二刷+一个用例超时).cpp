#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1000+10+5;
const int inf = 99999999;
int dis[N][N],n,m,k,ds,loc,d;
string c1,c2;
map<string,int>Name2id;
map<int,string>Id2name;

int main()
{
    cin>>n>>m>>k>>ds;
    loc=n+1;
    for(int i=1;i<=n+m;i++)
        for(int j=1;j<=n+m;j++)
            dis[i][j]=inf;
    for(int i=1;i<=n;i++)//¸øhouse±àºÅ
        Name2id[to_string(i)]=i;
    for(int i=1;i<=m;i++){//¸østation±àºÅ
        Name2id["G"+to_string(i)]=loc;
        Id2name[loc]="G"+to_string(i);
        loc++;
    }

    for(int i=0;i<k;i++){
        cin>>c1>>c2>>d;
        dis[Name2id[c1]][Name2id[c2]] = d;
        dis[Name2id[c2]][Name2id[c1]] = d;
    }

    //Floyd
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            for(int k=1;k<=n+m;k++){
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    int idx=-1;
    int maxDis=0,minHouseDis=inf,curDis;
    for(int i=n+1;i<loc;i++){
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
        cout<<Id2name[idx]<<endl;
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
