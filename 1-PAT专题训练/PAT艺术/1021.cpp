#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 1e4+5;
vector<int> Vec[N],tmp;
set<int> res;
int n,a,b,st,maxDep=0;
bool Vis[N];
void dfs(int x,int dep){
    Vis[x]=true;
    if(dep>maxDep){
        maxDep=dep;
        tmp.clear();
        tmp.push_back(x);
    }
    else if(dep==maxDep){
        tmp.push_back(x);
    }
    for(int i=0;i<Vec[x].size();i++)
        if(!Vis[Vec[x][i]])dfs(Vec[x][i],dep+1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        Vec[a].push_back(b);
        Vec[b].push_back(a);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!Vis[i]){
            cnt++,dfs(i,0);
        }
    }
    if(cnt>1){
        cout<<"Error: "<<cnt<<" components"<<endl;
    }
    else{
        fill(Vis,Vis+n+1,false);
        int root=tmp[0];
        for(int i=0;i<tmp.size();i++)res.insert(tmp[i]);
        tmp.clear();
        dfs(root,0);
        for(int i=0;i<tmp.size();i++) res.insert(tmp[i]);
        for(auto it=res.begin();it!=res.end();it++) cout<<*it<<endl;
    }
    return 0;
}
