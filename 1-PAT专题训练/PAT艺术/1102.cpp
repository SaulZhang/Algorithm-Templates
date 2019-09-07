#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 10+5;
vector<int> Vec[N],In,Lev;
int vis[N],n,root=0;
void Inorder(int x){
    if(Vec[x][0]!=-1)Inorder(Vec[x][0]);
    In.push_back(x);
    if(Vec[x][1]!=-1)Inorder(Vec[x][1]);
}
void LevelOrder(int x){
    queue<int> Que;
    Que.push(x);
    while(!Que.empty()){
        int top = Que.front();
        Lev.push_back(top);
        Que.pop();
        if(Vec[top][0]!=-1)Que.push(Vec[top][0]);
        if(Vec[top][1]!=-1)Que.push(Vec[top][1]);
    }
}
int main()
{
    char l,r;
    cin>>n;
    for(int i=0;i<n;i++)
        Vec[i].resize(2,-1);
    for(int i=0;i<n;i++){
        cin>>r>>l;//左右对调
        if(l!='-')Vec[i][0]=int(l-'0'),vis[int(l-'0')]=1;
        if(r!='-')Vec[i][1]=int(r-'0'),vis[int(r-'0')]=1;
    }
    while(root<n&&vis[root]==1)root++;
    Inorder(root);
    LevelOrder(root);
    for(int i=0;i<Lev.size();i++){
        cout<<Lev[i];
        if(i!=Lev.size()-1) cout<<" ";
    }
    cout<<endl;
    for(int i=0;i<In.size();i++){
        cout<<In[i];
        if(i!=In.size()-1) cout<<" ";
    }
    return 0;
}
