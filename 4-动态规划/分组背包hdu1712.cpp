/*
分组背包：hdu1712
http://acm.hdu.edu.cn/showproblem.php?pid=1712

*/

#include <iostream>

using namespace std;

int profit[101][101];
int dp[101];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&n==0)
            break;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&profit[i][j]);
            }
        }
        for(int i=0;i<=m;i++)
            dp[i]=0;

        //分组背包
        for(int i=1;i<=n;i++){
            for(int j=m;j>=0;j--){
                for(int k=1;k<=m;k++){
                    if(k<=j){
                        dp[j]=max(dp[j],dp[j-k]+profit[i][k]);
                    }
                }
            }
        }

        cout<<dp[m]<<endl;
    }
    return 0;
}
/*
2 2
1 2
1 3

2 2
2 1
2 1

2 3
3 2 1
3 2 1

0 0
*/
