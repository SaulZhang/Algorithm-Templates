#include <iostream>
#include <vector>
using namespace std;
const int N = 10000+5;
const int M = 1000+5;
vector<int> Vec[N],tmppath,pathU,pathV;
int m,n,x,root,u,v;
void Insert(int root,int x){
    if(x<root){
        if(Vec[root][0]==0)
            Vec[root][0] = x;
        else
            Insert(Vec[root][0],x);
    }
    else if(x>root){
        if(Vec[root][1]==0)
            Vec[root][1] = x;
        else
            Insert(Vec[root][1],x);
    }

}
void preOrder(int x){
    cout<<x<<" ";
    if(Vec[x][0]!=0)
        preOrder(Vec[x][0]);
    if(Vec[x][1]!=0)
        preOrder(Vec[x][1]);
}
void dfs(int x,int u,int v){
    tmppath.push_back(x);
    if(x==u)
        pathU = tmppath;
    if(x==v)
        pathV = tmppath;
    if(Vec[x][0]!=0)
        dfs(Vec[x][0],u,v);
    if(Vec[x][1]!=0)
        dfs(Vec[x][1],u,v);
    tmppath.pop_back();
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        Vec[i].push_back(0),Vec[i].push_back(0);
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i==1)
            root = x;
        else
            Insert(root,x);
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        if((u<1||u>n)&&(v<1||v>n)){
            cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
        }
        else if(u<1||u>n){
            cout<<"ERROR: "<<u<<" is not found."<<endl;
        }
        else if(v<1||v>n){
            cout<<"ERROR: "<<v<<" is not found."<<endl;
        }
        else{
            dfs(root,u,v);
            int ans=root;
            for(int j=0;j<min(pathU.size(),pathV.size());j++){
                if(pathU[j]==pathV[j])
                    ans = pathU[j];
                else
                    break;
            }
            if(ans==u){
                cout<<ans<<" is an ancestor of "<<v<<"."<<endl;
            }
            else if(ans==v){
                cout<<ans<<" is an ancestor of "<<u<<"."<<endl;
            }
            else{
                cout<<"LCA of "<<u<<" and "<<v<<" is "<<ans<<"."<<endl;
            }
        }

    }
    return 0;
}
/*
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99
*/
