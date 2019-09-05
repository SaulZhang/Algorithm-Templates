#include <iostream>
using namespace std;
const int N = 1e5+5;
const int inf = 99999999;
int n,m,e1,e2;
int sum[N];
int main()
{
    scanf("%d",&n);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&sum[i]); sum[i] += sum[i-1];
    }
    scanf("%d",&m);
    int fordis,backdis;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&e1,&e2);
        if(e1>e2) swap(e1,e2);
        if(e2-e1==0) fordis=backdis=0;
        else{
            fordis=sum[e2-1]-sum[e1-1];
            backdis = sum[e1-1]+(sum[n]-sum[n-1])+(sum[n-1]-sum[e2-1]);
        }
        cout<<min(fordis,backdis)<<endl;
    }
    return 0;
}
