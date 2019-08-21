#include <iostream>
#include <vector>
using namespace std;
const int N = 500+5;
int n,m,n1,n2,cnt=0,numOdd=0;
bool Vis[N];
vector<int>Vec[N];
void dfs(int x){
    Vis[x]=true;
    cnt++;
    for(int i=0;i<Vec[x].size();i++){
        if(!Vis[Vec[x][i]])
            dfs(Vec[x][i]);
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
    for(int i=1;i<=n;i++){
        cout<<Vec[i].size();
        if(i!=n)
            cout<<" ";
        else
            cout<<endl;
        if(Vec[i].size()%2!=0)
            numOdd++;
    }
    dfs(1);
    if(numOdd==0&&cnt==n){
        cout<<"Eulerian"<<endl;
    }
    else if(numOdd==2&&cnt==n){
        cout<<"Semi-Eulerian"<<endl;
    }
    else{
        cout<<"Non-Eulerian"<<endl;
    }
    return 0;
}
/*
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6
*/
