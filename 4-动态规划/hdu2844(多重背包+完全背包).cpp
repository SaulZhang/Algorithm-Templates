#include <iostream>

#define N 101
#define M 100001

using namespace std;

int A[N];
int C[N];
int dp[M];

int main()
{
    int n,m;

    while(~scanf("%d%d",&n,&m)){

        if(m==0&&n==0)
            break;

        for(int i=1;i<=n;i++){
            cin>>A[i];
        }

        for(int i=1;i<=n;i++){
            cin>>C[i];
        }

        for(int i=0;i<=M;i++)
            dp[i]=0;

        for(int i=1;i<=n;i++){
            if(C[i]*A[i]>=m){//完全背包
                for(int j=A[i];j<=m;j++){
                    dp[j] = max(dp[j],dp[j-A[i]]+A[i]);
                }
            }
            else{//多重背包+二进制优化
                for(int k=1;C[i]-k>=0;k*=2){
                    for(int j=m;j>=A[i]*k;j--){
                        dp[j] = max(dp[j],dp[j-A[i]*k]+A[i]*k);
                    }
                    C[i]-=k;
                }
                if(C[i]>0){
                    for(int j=m;j>=A[i]*C[i];j--){
                        dp[j] = max(dp[j],dp[j-A[i]*C[i]]+A[i]*C[i]);
                    }
                }

            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(dp[i]==i){
                ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

/*
3 10
1 2 4
2 1 1

2 5
1 4
2 1
0 0
*/
