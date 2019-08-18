#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 10000+5;
vector<int>Vec[N],pathU,pathV,tmppath;//这题的陷阱就在于没有说结点的编号就是1~n之间的，so...
int inOrder[N],preOrder[N],m,n;
map<int,bool> Ma;
map<int,int>val2idx;
void dfs(int x,int u,int v){
    tmppath.push_back(x);
    if(x==u) pathU = tmppath;
    if(x==v) pathV = tmppath;
    if(Vec[x][0]!=0) dfs(Vec[x][0],u,v);
    if(Vec[x][1]!=0) dfs(Vec[x][1],u,v);
    tmppath.pop_back();
}
int build(int pst,int ped,int ist,int ied){
    int rootIdx=ist;
    while(rootIdx<=ied&&preOrder[pst]!=inOrder[rootIdx])rootIdx++;
    int len = rootIdx-ist;
    if(rootIdx!=ist) Vec[pst][0] = build(pst+1,pst+len,ist,rootIdx-1);
    if(rootIdx!=ied) Vec[pst][1] = build(pst+len+1,ped,rootIdx+1,ied);
    return pst;//树里面存储的是结点的编号i，而结点的值必须通过preOrder[i]来获得
}
int main()
{
    for(int i=1;i<N;i++){//init
        Vec[i].push_back(0);Vec[i].push_back(0);
    }
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>inOrder[i],Ma[inOrder[i]]=true;
    for(int i=1;i<=n;i++) cin>>preOrder[i],Ma[preOrder[i]]=true,val2idx[preOrder[i]]=i;
    build(1,n,1,n);
    int root = 1,u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        if(!Ma[u]&&!Ma[v])
            cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
        else if(!Ma[u])
            cout<<"ERROR: "<<u<<" is not found."<<endl;
        else if(!Ma[v])
            cout<<"ERROR: "<<v<<" is not found."<<endl;
        else{
            //少了这行会出现段错误
            dfs(1,val2idx[u],val2idx[v]);
            int ans;
            for(int i=0;i<min(int(pathU.size()),int(pathV.size()));i++){
                if(pathU[i]==pathV[i])
                    ans=preOrder[pathU[i]];
                else
                    break;
            }
            if(ans==u)
                cout<<u<<" is an ancestor of "<<v<<"."<<endl;
            else if(ans==v)
                cout<<v<<" is an ancestor of "<<u<<"."<<endl;
            else
                cout<<"LCA of "<<u<<" and "<<v<<" is "<<ans<<"."<<endl;
        }
    }
    return 0;
}
/*
5 1
4
4 4
2 3

6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 1
7 9
12 -3
0 8
99 99

100 10
8 9 1 7 3 4 10 5 2 6
4 7 1 8 9 3 2 5 10 6

*/
