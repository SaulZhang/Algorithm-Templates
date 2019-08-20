#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N = 10000+5;
const int M = 100+5;
vector<int> Vec[N],tmppath,path;
map<int,vector<int>> Ma;
map<int,bool>Vis;
int n,m,s,k,A[M],u,v,minLen=10000,minchange=10000;
set<int> tmpS,tmpS1;
void dfs(int x,int v,int dep){
    tmppath.push_back(x);
    Vis[x] = true;
    if(x==v){
        int cnt=0;
        tmpS1.clear();
        //计算换乘的次数
        for(int i=1;i<tmppath.size();i++){
            tmpS.clear();
            for(int j=0;j<Ma[tmppath[i-1]].size();j++)
                tmpS.insert(Ma[tmppath[i-1]][j]);
            for(int j=0;j<Ma[tmppath[i]].size();j++){
                if(tmpS.find(Ma[tmppath[i]][j])!=tmpS.end()){
                    tmpS1.insert(Ma[tmppath[i]][j]);
                    break;
                }
            }
        }
        cnt = tmpS1.size()-1;
        if(minLen>tmppath.size()){
            path = tmppath;
            minLen = tmppath.size();
            minchange = cnt;
        }
        else if(minLen==tmppath.size()&&minchange>cnt){
            path = tmppath;
            minchange = cnt;
        }
    }
    else{
        for(int i=0;i<Vec[x].size();i++){
            if(!Vis[Vec[x][i]])
                dfs(Vec[x][i],v,dep+1);
        }
    }
    tmppath.pop_back();
    Vis[x] = false;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>A[j];
            Ma[A[j]].push_back(i);
        }
        for(int j=1;j<m;j++){
            Vec[A[j]].push_back(A[j-1]);
            Vec[A[j-1]].push_back(A[j]);
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>u>>v;
        path.clear();
        Vis.clear();
        minLen=10000,minchange=10000;
        dfs(u,v,1);
        tmpS1.clear();
        int cur=0,st=u,ed;
        cout<<path.size()-1<<endl;
        for(int i=1;i<path.size();i++){
            tmpS.clear();
            for(int j=0;j<Ma[path[i-1]].size();j++)
                tmpS.insert(Ma[path[i-1]][j]);
            for(int j=0;j<Ma[path[i]].size();j++){
                if(tmpS.find(Ma[path[i]][j])!=tmpS.end()){
                    if(tmpS1.find(Ma[path[i]][j])==tmpS1.end()){
                        if(tmpS1.size()!=0){
                            printf("Take Line#%d from %04d to %04d.\n",cur,st,path[i-1]);
                        }
                        tmpS1.insert(Ma[path[i]][j]);
                        cur = Ma[path[i]][j];
                        st = path[i-1];
                    }
                    break;
                }
            }
        }
        if(st!=path[path.size()-1]){
            printf("Take Line#%d from %04d to %04d.\n",cur,st,v);
        }

//        for(int j=0;j<path.size();j++){
//            cout<<path[j];
//            if(j!=path.size()-1)
//                cout<<"->";
//            else
//                cout<<endl;
//        }
    }

    return 0;
}
/*
4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
3
3011 3013
6666 2001
2004 3001
*/
