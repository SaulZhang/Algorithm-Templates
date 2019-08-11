#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000+5;
const int M = N*(N -1)/2;

struct Edge{
    int u;
    int v;
}edge[M];

int Tree[N];

int getRoot(int x){
    if(Tree[x]==-1){
        return x;
    }
    else{
        return Tree[x]=getRoot(Tree[x]);
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v;
    }
    int x;
    for(int i=0;i<k;i++){
        cin>>x;
        fill(Tree+1,Tree+n+1,-1);
//        for(int j=1;j<=n;j++)
//            Tree[j]=-1;

        for(int j=0;j<m;j++){
            if(edge[j].u==x||edge[j].v==x)
                continue;
            int rootA = getRoot(edge[j].u);
            int rootB = getRoot(edge[j].v);

            if(rootA!=rootB){
                Tree[rootA]=rootB;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            if(Tree[j]==-1&&j!=x){
                ans++;
            }
        }
        cout<<ans-1<<endl;
    }

    return 0;
}
/*
3 2 3
1 2
1 3
1 2 3
*/
