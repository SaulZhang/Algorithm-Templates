#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;
const int N = 30+5;
int n,inOrder[N],postOrder[N],depth[N]={0},maxDep=0;
bool Vis[N];
vector<int> Vec[N],tmp;
queue<int> Que;
int build(int ist,int ied,int pst,int ped){
    int rootId = ist;
    while(inOrder[rootId]!=postOrder[ped]&&rootId<=ied)rootId++;
    int len = rootId-ist;
    if(rootId!=ist) Vec[rootId][0] = build(ist,rootId-1,pst,pst+len-1);
    if(rootId!=ied) Vec[rootId][1] = build(rootId+1,ied,pst+len,ped-1);
    return rootId;
}
void dfs(int x,int dep){
    depth[dep]++;
    if(dep>maxDep)
        maxDep = dep;
    if(Vec[x][0]!=0)
        dfs(Vec[x][0],dep+1);
    if(Vec[x][1]!=0)
        dfs(Vec[x][1],dep+1);
}
void bfs(int x){
    Que.push(x);
    Vis[x]=true;

    while(!Que.empty()){
        int top = Que.front();
        tmp.push_back(top);
        Que.pop();
        if(Vec[top][0]!=0){
            Que.push(Vec[top][0]);
            Vis[Vec[top][0]]=true;
        }
        if(Vec[top][1]!=0){
            Que.push(Vec[top][1]);
            Vis[Vec[top][1]]=true;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)Vec[i].push_back(0),Vec[i].push_back(0);
    for(int i=1;i<=n;i++) cin>>inOrder[i];
    for(int i=1;i<=n;i++) cin>>postOrder[i];
    int root = build(1,n,1,n);
    dfs(root,1);
    bfs(root);
    int cnt=0,idx=1;
    string ans="";
    stack<int> tmpS;
    while(cnt<=n&&idx<=maxDep){
        if(idx%2==0){//正
            for(int i=0;i<depth[idx];i++)
                ans+=to_string(inOrder[tmp[cnt+i]])+" ";
            cnt+=depth[idx];
            idx++;
        }
        else{//反
            for(int i=0;i<depth[idx];i++)
                tmpS.push(inOrder[tmp[cnt+i]]);
            while(!tmpS.empty()){
                ans+=to_string(tmpS.top())+" ";
                tmpS.pop();
            }
            cnt+=depth[idx];
            idx++;
        }
    }
    cout<<ans.substr(0,ans.size()-1)<<endl;
    return 0;
}
/*
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
*/
