/*
分成两部分，如果是连通图的话，那就直接以各个结点作为起点进行dfs，统计各自所能得到的深度。
如果不是连通的图，那么就采用并查集求解出整个图中连通分量的个数。
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int N = 10000+5;
int n,edge[N][2],maxDepth=0,root,mark[N]={0},Tree[N],k=0;
set<int>res;
vector<int>Vec[N];
void dfs(int x,int d){
    mark[x]=1;
    if(d>maxDepth){
        maxDepth = d;
        res.clear();
        res.insert(root);
    }
    else if(d==maxDepth){
        res.insert(root);
    }
    for(int i=0;i<Vec[x].size();i++){
        if(mark[Vec[x][i]]==0) dfs(Vec[x][i],d+1);
    }
}
int findRoot(int x){
    if(Tree[x]==-1)
        return x;
    else
        return Tree[x]=findRoot(Tree[x]);
}
int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>edge[i][0]>>edge[i][1];
        Vec[edge[i][0]].push_back(edge[i][1]);
        Vec[edge[i][1]].push_back(edge[i][0]);
    }
    root = 1; dfs(root,1);
    bool flag = true;
    for(int i=1;i<=n;i++){//非连通
        if(!mark[i]){
            flag=false; break;
        }
    }
    if(flag){
        for(int i=2;i<=n;i++){
            if(Vec[i].size()>=2) continue;
            fill(mark,mark+n+1,0);
            root = i; dfs(root,1);
        }
        for(auto it=res.begin();it!=res.end();it++)
            cout<<*it<<endl;
    }
    else{//并查集问题
        fill(Tree+1,Tree+1+n,-1);
        for(int i=0;i<n-1;i++){
            int a = findRoot(edge[i][0]);
            int b = findRoot(edge[i][1]);
            if(a!=b) Tree[a] = b;
        }
        for(int i=1;i<=n;i++)
            if(Tree[i]==-1)k++;
        cout<<"Error: "<<k<<" components"<<endl;
    }
    return 0;
}
