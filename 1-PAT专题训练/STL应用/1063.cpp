#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
const int N  = 50+5;
unordered_set<int> tmpS[N];
unordered_map<int,bool> isVis;
int n,m,x,k,a,b,Nc,Nt;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>x;
            tmpS[i].insert(x);
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>a>>b;
        Nc=0;
        isVis.clear();
        for(auto it=tmpS[a].begin();it!=tmpS[a].end();it++){
            isVis[*it]=true;
        }
        Nt=isVis.size();
        for(auto it=tmpS[b].begin();it!=tmpS[b].end();it++){
            if(isVis[*it]){
                Nc++;
            }
            else{
                Nt++;
            }
        }
        printf("%.1f%\n",1.0*Nc/Nt*100.);
    }
    return 0;
}
