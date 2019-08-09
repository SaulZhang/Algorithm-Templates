/*
学习思路：对于要按照从大到小的顺序来打印结点，没有必要报所有的
路径都存起来最后在进行排序。只需在构建树的时候，对于所有结点的
子节点按照权重的大小进行排序即可。这样根据dfs的特点，搜索的路径
自然就是有序的。
同时：代码越短，出错的概率就越小。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100+5;
const int inf = 99999999;
vector<int> Vec[N],tmpPath;
long long weight[N],curSum=0,s;
int n,m,id,k,ch;
void dfs(int x){
    curSum+=weight[x];
    tmpPath.push_back(weight[x]);
    if(Vec[x].size()==0){
        if(curSum==s){
            for(int i=0;i<tmpPath.size();i++){
                cout<<tmpPath[i];
                if(i!=tmpPath.size()-1)
                    cout<<" ";
                else
                    cout<<endl;
            }
        }
    }
    else{
        for(int i=0;i<int(Vec[x].size());i++)
            dfs(Vec[x][i]);
    }
    tmpPath.pop_back();
    curSum-=weight[x];
}
bool cmp(int a,int b){
    return weight[a]>weight[b];
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
        sort(Vec[id].begin(),Vec[id].end(),cmp);
    }
    dfs(0);
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
