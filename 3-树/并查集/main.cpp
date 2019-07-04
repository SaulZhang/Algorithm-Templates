/*
hdu 1232
并查集的入门基础题
*/
#include <iostream>
using namespace std;

int Tree[1000];

int findRoot(int x){
    if(Tree[x]=-1){
        return x;
    }
    return Tree[x]=findRoot(Tree[x]);
}

int main()
{
    int n,m;
    while(~scanf("%d",&n)){
        if(n==0)
            break;
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
            Tree[i]=-1;
        int a,b;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);

            int rootA = findRoot(a);
            int rootB = findRoot(b);

            if(rootB!=rootA)
                Tree[rootA] = rootB;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(Tree[i]==-1)
                cnt++;
        cout<<cnt-1<<endl;
    }

    return 0;
}
/*
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
*/
