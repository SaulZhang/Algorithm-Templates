#include <iostream>
#include <vector>
using namespace std;
const int N = 100;
vector<int> Vec[N];
int Num[N];
int maxDep = 0;
void dfs(int id,int depth){
    if(Vec[id].size()==0)
        Num[depth]++,maxDep=max(maxDep,depth);
    for(int i=0;i<Vec[id].size();i++)
        dfs(Vec[id][i],depth+1);
}
int main()
{
    int n,m,id,k,ch;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            cin>>ch;
            Vec[id].push_back(ch);
        }
    }
    dfs(1,0);
    for(int i=0;i<=maxDep;i++){
        cout<<Num[i];
        if(i!=maxDep)
            cout<<" ";
    }
    return 0;
}
/*
2 1
01 1 02
*/
