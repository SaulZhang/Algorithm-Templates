#include <iostream>
#include <memory.h>

#define N 101
#define C 1001
using namespace std;

int w[N],v[N];

int dp[C];

//0-1背包
int BackPack1(int n,int c){

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=c;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    return dp[c];
}


//0-N背包(完全背包)
int BackPack2(int n,int c){

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=c;j++){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    return dp[c];
}

//多重背包




int main()
{
    int n,c;
    while(~scanf("%d%d",&n,&c)){
        for(int i=1;i<=n;i++)
            scanf("%d",&w[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&v[i]);

        cout<<BackPack2(n,c)<<endl;

    }
    return 0;
}
/*
4 50
10 20 30 20
5 5 7 9
*/
