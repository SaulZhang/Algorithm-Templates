#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3+5;
set<int> S[N];
int Tree[N],num[N];
bool Vis[N];
int findRoot(int x){
    if(Tree[x]==-1)
        return x;
    else
        return Tree[x]=findRoot(Tree[x]);
}
int main()
{
    int n,k,h;
    cin>>n;
    fill(Tree,Tree+N,-1);
    fill(num,num+N,1);
    for(int i=1;i<=n;i++){
        scanf("%d: ",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&h);
            S[i].insert(h);
        }
    }
    int rootA,rootB;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bool flag = false;
            if(Vis[i]&&Vis[j])continue;
            for(auto it=S[i].begin();it!=S[i].end();it++){
                if(S[j].find(*it)!=S[j].end()){
                    flag=true;
                    rootA = findRoot(i);
                    rootB = findRoot(j);
                    if(rootA!=rootB){
                        Tree[rootA]=rootB;
                        num[rootB]+=num[rootA];
                        Vis[i]=true;
                    }
                    break;
                }
            }
            if(flag){
                for(auto it=S[rootA].begin();it!=S[rootA].end();it++){
                    S[rootB].insert(*it);
                }
            }
        }
    }
    vector<int> tmp;
    for(int i=1;i<=n;i++){
        if(Tree[i]==-1)
            tmp.push_back(num[i]);
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    cout<<tmp.size()<<endl;
    for(int i=0;i<tmp.size();i++){
        printf("%d",tmp[i]);
        if(i!=tmp.size()-1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
*/
