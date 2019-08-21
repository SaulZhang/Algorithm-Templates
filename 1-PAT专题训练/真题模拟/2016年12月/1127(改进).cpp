#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 30+5;
int n,inOrder[N],postOrder[N],maxDep=0;
vector<int> Vec[N],depth[N];
int build(int ist,int ied,int pst,int ped){
    int rootId = ist;
    while(inOrder[rootId]!=postOrder[ped]&&rootId<=ied)rootId++;
    int len = rootId-ist;
    if(rootId!=ist){
        Vec[rootId][0] = build(ist,rootId-1,pst,pst+len-1);
    }
    if(rootId!=ied) {
        Vec[rootId][1] = build(rootId+1,ied,pst+len,ped-1);
    }
    return rootId;
}
void dfs(int x,int dep){
    depth[dep].push_back(x);
    if(dep>maxDep)maxDep = dep;
    if(Vec[x][0]!=0)dfs(Vec[x][0],dep+1);
    if(Vec[x][1]!=0)dfs(Vec[x][1],dep+1);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) Vec[i].push_back(0),Vec[i].push_back(0);
    for(int i=1;i<=n;i++) cin>>inOrder[i];
    for(int i=1;i<=n;i++) cin>>postOrder[i];
    int root = build(1,n,1,n);
    dfs(root,1);
    string ans="";
    for(int i=1;i<=maxDep;i++){
        if(i%2==1){//右→左
            for(int j=depth[i].size()-1;j>=0;j--)
                ans+=to_string(inOrder[depth[i][j]])+" ";
        }
        else{
            for(int j=0;j<depth[i].size();j++)
                ans+=to_string(inOrder[depth[i][j]])+" ";
        }
    }
    cout<<ans.substr(0,ans.size()-1)<<endl;
    return 0;
}
