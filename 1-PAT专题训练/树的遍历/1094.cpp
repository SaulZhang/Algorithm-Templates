#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100+5;
vector<int> Vec[N];
int n,m,maxNum=0,maxDep=0,k,ch,id,Num[N];
void dfs(int x,int dep){
    maxDep = max(maxDep,dep);
    Num[dep]++;
    for(int i=0;i<Vec[x].size();i++)
        dfs(Vec[x][i],dep+1);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            cin>>ch;Vec[id].push_back(ch);
        }
    }
    dfs(1,1);
    maxNum = *max_element(Num+1,Num+maxDep+1);
    maxDep = max_element(Num+1,Num+maxDep+1)-Num;
    cout<<maxNum<<" "<<maxDep<<endl;
    return 0;
}
