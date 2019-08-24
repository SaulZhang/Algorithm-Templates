#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4+5;
int Tree[N],numBird,n,m,bird[N],k,b1,b2;
int findRoot(int x){
    if(Tree[x]==-1)
        return x;
    else
        return Tree[x]=findRoot(Tree[x]);
}
int main()
{
    cin>>n;
    fill(Tree+1,Tree+N,-1);
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>bird[j];
            numBird = max(numBird,bird[j]);
            if(j==1)
                continue;
            else{
                int rootA = findRoot(bird[1]);
                int rootB = findRoot(bird[j]);
                if(rootA!=rootB)
                    Tree[rootA]=rootB;
            }
        }
    }
    int numTree=0;
    for(int i=1;i<=numBird;i++){
        if(Tree[i]==-1)numTree++;
    }
    cout<<numTree<<" "<<numBird<<endl;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>b1>>b2;
        if(findRoot(b1)!=findRoot(b2))
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
/*
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
5
10 5
3 7
*/
