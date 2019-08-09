/*
有一个样例没有过，扣了2分
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100+5;
const int inf = 99999999;
vector<int> Vec[N],tmpPath;
vector<vector<int>> ans;
long long weight[N],curSum=0,s;
int n,m,id,k,ch;
void dfs(int x){
    curSum+=weight[x];
    tmpPath.push_back(weight[x]);
    if(Vec[x].size()==0){
        if(curSum==s)
            ans.push_back(tmpPath);
    }
    else{
        for(int i=0;i<int(Vec[x].size());i++)
            dfs(Vec[x][i]);
    }
    tmpPath.pop_back();
    curSum-=weight[x];
}
int main()
{
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
        cin>>weight[i];
    for(int i=0;i<m;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            cin>>ch;
            Vec[id].push_back(ch);
        }
    }
    dfs(0);
    //处理输出部分
    int maxLen=0;
    for(int i=0;i<int(ans.size());i++)
        maxLen=max(maxLen,int(ans[i].size()));
    int mark[int(ans.size())];
    fill(mark,mark+int(ans.size()),0);
    int order[int(ans.size())];
    int cnt=0;
    for(int i=0;i<maxLen;i++){//第i列
        for(int j=0;j<int(ans.size());j++){//第j行
            if(mark[j]==1)
                continue;
            bool flag=true;
            for(int l=0;l<int(ans.size());l++){//0~n行
                if(int(ans[l].size())<=i)
                    continue;
                if(l!=j&&ans[l][i]>=ans[j][i]&&mark[l]==0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                order[cnt++]=j;
                mark[j]=1;
            }
        }
    }
    for(int i=0;i<int(ans.size());i++)
        if(mark[i]==0)
            order[cnt++]=i;
    for(int i=0;i<cnt;i++){
        for(int j=0;j<int(ans[order[i]].size());j++){
            cout<<ans[order[i]][j];
            if(j!=int(ans[order[i]].size())-1)
                cout<<" ";
            else
                cout<<endl;
        }
    }
    return 0;
}
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
