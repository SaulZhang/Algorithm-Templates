#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int N = 100+5;
map<int,int>Num;
vector<int> Vec[N];
int n,m,id,k,ch;
void dfs(int x,int dep){
    if(Vec[x].size()==0) Num[dep]++;
    else if(Num.count(dep)==0) Num[dep]=0;
    for(int i=0;i<Vec[x].size();i++) dfs(Vec[x][i],dep+1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>id>>k;
        for(int j=1;j<=k;j++){
            cin>>ch;
            Vec[id].push_back(ch);
        }
    }
    dfs(1,1);
    int s = Num.size(),cnt=0;
    for(auto it=Num.begin();it!=Num.end();it++){
        cnt++;
        cout<<it->second;
        if(cnt!=s) cout<<" ";
    }
    return 0;
}
