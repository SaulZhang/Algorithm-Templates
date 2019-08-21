#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
const int N = 10000+5;
const int M = 100+5;
vector<int> Vec[N],tmppath,path;
unordered_map<int,unordered_map<int,int>> Ma;
bool Vis[N];
int n,m,s,k,A[M],u,v,minLen=10000,minchange=10000;
void dfs(int x,int v,int dep){
    tmppath.push_back(x);
    Vis[x] = true;
    if(x==v){
        int cnt=0,pre=0;
        //计算换乘的次数
        for(int i=1;i<tmppath.size();i++){
            if(i==1)pre=Ma[tmppath[i]][tmppath[i-1]];
            if(pre!=Ma[tmppath[i]][tmppath[i-1]])cnt++;
            pre = Ma[tmppath[i]][tmppath[i-1]];
        }
        if(minLen>tmppath.size()){
            path = tmppath;minLen = tmppath.size();minchange = cnt;
        }
        else if(minLen==tmppath.size()&&minchange>cnt){
            path = tmppath;minchange = cnt;
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
            if(j!=0){
                Ma[A[j]][A[j-1]] = i;Ma[A[j-1]][A[j]] = i;
            }
        }
        for(int j=1;j<m;j++){
            Vec[A[j]].push_back(A[j-1]);Vec[A[j-1]].push_back(A[j]);
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>u>>v;
        path.clear();
        fill(Vis+1,Vis+1+n,false);
        minLen=10000,minchange=10000;
        dfs(u,v,1);
        int cur=0,st=u,pre=0;
        cout<<path.size()-1<<endl;
        for(int i=1;i<path.size();i++){
            if(i==1)pre=Ma[path[i]][path[i-1]];
            if(pre!=Ma[path[i]][path[i-1]]){
                printf("Take Line#%d from %04d to %04d.\n",pre,st,path[i-1]);
                st = path[i-1];
            }
            pre = Ma[path[i]][path[i-1]];
        }
        printf("Take Line#%d from %04d to %04d.\n",pre,st,v);
    }
    return 0;
}
