#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N=10000+5;
int n,m,k,color[N],n1,n2,mark[N];
vector<int> Vec[N];
map<int,int> Map;
bool flag=true;
void dfs(int x){
    mark[x]=1;
    for(int i=0;i<Vec[x].size();i++){
        if(color[Vec[x][i]]==color[x]){
            flag=false;
            return;
        }
        if(mark[Vec[x][i]]==0){
            dfs(Vec[x][i]);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>n1>>n2;
        Vec[n1].push_back(n2);
        Vec[n2].push_back(n1);
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        Map.clear();
        for(int j=0;j<n;j++){
            cin>>color[j];
            Map[color[j]]=1;
        }
        fill(mark,mark+n,0);
        flag=true;
        dfs(0);
        if(flag)
            cout<<Map.size()<<"-coloring"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
4
0 1 0 1 4 1 0 1 3 0
0 1 0 1 4 1 0 1 0 0
8 1 0 1 4 1 0 5 3 0
1 2 3 4 5 6 7 8 8 9
*/
