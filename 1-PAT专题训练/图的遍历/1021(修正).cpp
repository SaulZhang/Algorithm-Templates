/*
思路类似于求树的最长直径，采用两次dfs，第一次dfs得到的结果均插入到answer中，
再随机选answer中一个结点作为dfs的起点，再将得到的其他结点插入到answer中。
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int N = 10000+5;
int n,maxDepth=0,mark[N],Tree[N],k=0,n1,n2;
set<int>res;
vector<int>Vec[N],tmp;
void dfs(int x,int d){
    mark[x]=1;
    if(d>maxDepth){
        maxDepth = d;
        tmp.clear();
        tmp.push_back(x);
    }
    else if(d==maxDepth){
        tmp.push_back(x);
    }
    for(int i=0;i<Vec[x].size();i++){
        if(mark[Vec[x][i]]==0){
            dfs(Vec[x][i],d+1);
        }
    }
}
int main()
{
    cin>>n;
    fill(mark+1,mark+n+1,0);
    for(int i=0;i<n-1;i++){
        cin>>n1>>n2;
        Vec[n1].push_back(n2);
        Vec[n2].push_back(n1);
    }
    int cnt=0;//计算连通分量的个数
    for(int i=1;i<=n;i++){
        if(mark[i]==0){
            dfs(i,1);
            cnt++;
        }
    }
    if(cnt==1){
        //第二次dfs，以之前找到的任意一个结点为根
        fill(mark+1,mark+n+1,0);
        int root = tmp[0];
        for(int i=0;i<tmp.size();i++)//注意这里需要把第一次dfs得到的所有的结点插入到set中
            res.insert(tmp[i]);
        tmp.clear();
        dfs(root,1);
        for(int i=0;i<tmp.size();i++)
            res.insert(tmp[i]);
        for(auto it=res.begin();it!=res.end();it++)
            cout<<*it<<endl;
    }
    else{//并查集问题
        cout<<"Error: "<<cnt<<" components"<<endl;
    }
    return 0;
}
