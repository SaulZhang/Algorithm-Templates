#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int N = 2000+5;
int n,k,W_Node[N]={0},w,loc=0,head,totNum,totWeight;
int edge[N][N];//存储结点之间的权重
bool mark[N];
map<string,int>Name2id,Ans;
map<int,string>Id2name;
string str1,str2;
void dfs(int u,int& totNum,int&totWeight){
    totNum++;
    for(int v=0;v<loc;v++)
        if(edge[u][v]>0)
            totWeight+=edge[u][v];
    mark[u]=true;
    if(W_Node[u]>W_Node[head]){
        head = u;
    }
    for(int v=0;v<loc;v++){
        if(edge[u][v]>0&&!mark[v])
            dfs(v,totNum,totWeight);
    }
}
int main()
{
    fill(edge[0],edge[0]+N*N,0);
    cin>>n>>k;
    for(int i=0;i<n;i++){//name to id
        cin>>str1>>str2>>w;
        if(Name2id.count(str1)==0){
            Name2id[str1]=loc;Id2name[loc]=str1;loc++;
        }
        if(Name2id.count(str2)==0){
            Name2id[str2]=loc;Id2name[loc]=str2;loc++;
        }
        edge[Name2id[str1]][Name2id[str2]] = w;
        W_Node[Name2id[str1]] += w;
        W_Node[Name2id[str2]] += w;
    }
    for(int i=0;i<loc;i++){
        if(!mark[i]){
            head = i;totNum=0,totWeight=0;
            dfs(i,totNum,totWeight);
            if(totNum>2&&totWeight>k){
                Ans[Id2name[head]] = totNum;
            }
        }
    }
    cout<<Ans.size()<<endl;
    for(auto it=Ans.begin();it!=Ans.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    return 0;
}
