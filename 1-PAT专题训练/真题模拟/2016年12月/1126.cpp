#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500+5;
int n,m,degree[N],n1,n2;
int Tree[N];
int findRoot(int x){
    if(Tree[x]==-1)
        return x;
    else
        return Tree[x]=findRoot(Tree[x]);
}
int main()
{
    cin>>n>>m;
    if(n==1){
        cout<<0<<endl;
        cout<<"Non-Eulerian"<<endl;
        return 0;
    }
    fill(Tree+1,Tree+1+n,-1);
    for(int i=1;i<=m;i++){
        cin>>n1>>n2;
        degree[n1]++,degree[n2]++;
        int rootA = findRoot(n1);
        int rootB = findRoot(n2);
        if(rootA!=rootB)
            Tree[rootA] = rootB;
    }
    for(int i=1;i<=n;i++){
        cout<<degree[i];
        if(i!=n)
            cout<<" ";
        else
            cout<<endl;
    }
    int oddCnt=0,fenl=0;
    for(int i=1;i<=n;i++)
        if(degree[i]%2!=0)
            oddCnt++;
    //连通分量的个数(去除掉孤立的点)
    for(int i=1;i<=n;i++){
        if(Tree[i]==-1&&degree[i]!=0)
            fenl++;
    }
    if(oddCnt==0&&fenl==1)
        cout<<"Eulerian"<<endl;
    else if(oddCnt==2&&fenl==1)
        cout<<"Semi-Eulerian"<<endl;
    else
        cout<<"Non-Eulerian"<<endl;
    return 0;
}
