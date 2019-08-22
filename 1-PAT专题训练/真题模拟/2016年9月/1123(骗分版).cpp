#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 20+5;
vector<int>Vec[N],res;
int n,x,A[N];
bool vis[N];
queue<int> Que;
void Insert(int root,int x){
    if(A[x]<A[root]){
        if(Vec[root][0]==-1)
            Vec[root][0]=x;
        else
            Insert(Vec[root][0],x);
    }
    if(A[x]>A[root]){
        if(Vec[root][1]==-1)
            Vec[root][1]=x;
        else
            Insert(Vec[root][1],x);
    }
}
void bfs(int root){
    Que.push(root);
    vis[root]=true;
    while(!Que.empty()){
        int top = Que.front();
        res.push_back(A[top]);
        Que.pop();
        if(Vec[top][0]!=-1&&!vis[Vec[top][0]]){
            Que.push(Vec[top][0]);
            vis[Vec[top][0]]=true;
        }
        if(Vec[top][1]!=-1&&!vis[Vec[top][1]]){
            Que.push(Vec[top][1]);
            vis[Vec[top][1]]=true;
        }
    }

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        Vec[i].push_back(-1),Vec[i].push_back(-1);
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    for(int i=2;i<=n;i++){
        Insert(1,i);
    }
    bfs(1);
    for(int i=0;i<n;i++){
        cout<<res[i];
        if(i==n-1)
            cout<<endl;
        else
            cout<<" ";
    }
    bool flag=true;
    for(int i=1;i<=n/2;i++){
        if(i!=n/2){
            if(Vec[i][0]==-1||Vec[i][1]==-1){
                flag = false;
                break;
            }
        }
        else{
            if(Vec[i][0]==-1&&Vec[i][1]!=-1){
                flag = false;
                break;
            }
        }
    }
    if(flag==false)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

    return 0;
}
/*
5
88 70 61 63 65
*/
