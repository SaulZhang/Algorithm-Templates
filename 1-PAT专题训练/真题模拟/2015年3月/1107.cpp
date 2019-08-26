#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3+5;
int Tree[N],num[N];
bool Vis[N];
int findRoot(int x){
    if(Tree[x]==-1)
        return x;
    else
        return Tree[x]=findRoot(Tree[x]);
}
void Union(int a,int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA!=rootB){
        Tree[rootA]=rootB;
    }
}
int main()
{
    int n,k,h,course[N]={0};
    cin>>n;
    fill(Tree,Tree+N,-1);
    for(int i=1;i<=n;i++){
        scanf("%d: ",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&h);
            if(course[h]==0)
                course[h]=i;
            Union(i,course[h]);
        }
    }
    vector<int> Ans(n+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        Ans[findRoot(i)]++;
    }
    for(int i=1;i<=n;i++){
        if(Ans[i]!=0)
            cnt++;
    }
    sort(Ans.begin(),Ans.end(),greater<int>());
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        printf("%d",Ans[i]);
        if(i!=cnt-1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
