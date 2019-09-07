#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const int N = 1e5+5;
int n,k,ch;
double p,r,Sum=0;
map<int,int>Ma;
vector<int>Vec[N];
void dfs(int x,int dep){
    if(Vec[x].size()==0)
        Sum+=p*pow(1.0+r/100,dep)*Ma[x];
    for(int i=0;i<Vec[x].size();i++)
        dfs(Vec[x][i],dep+1);
}
int main()
{
    scanf("%d %lf %lf",&n,&p,&r);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        if(k==0){
            scanf("%d",&ch); Ma[i]=ch;
        }
        else{
            for(int j=0;j<k;j++){
                scanf("%d",&ch);
                Vec[i].push_back(ch);
            }
        }
    }
    dfs(0,0);
    printf("%.1f",Sum);
    return 0;
}
