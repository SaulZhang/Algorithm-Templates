#include <iostream>
#include <memory.h>

#define C 101
#define M 101
using namespace std;

int p[M],w[M],k[M];
int dp[C];

int main()
{
    int T;
    int c,m;
    cin>>T;
    for(int t=1;t<=T;t++){//��������

        memset(dp,0,sizeof(dp));

        cin>>c>>m;
        for(int i=1;i<=m;i++)
            cin>>p[i]>>w[i]>>k[i];

        for(int i=1;i<=m;i++){//����ÿһ����Ʒ
            int num = k[i];
            for(int l = 1;num-l>=0;l*=2){//��ÿһ����Ʒ�������������ж����Ʋ��
                for(int j=c;j>=p[i]*l;j--){//�Ѳ��֮�����Ʒ����һ����Ʒ���뵽������
                    dp[j]=max(dp[j],dp[j-p[i]*l]+w[i]*l);
                }
                num-=l;
            }
            if(num!=0){
                for(int j=c;j>=p[i]*num;j--){
                    dp[j]=max(dp[j],dp[j-p[i]*num]+w[i]*num);
                }
            }
        }

        cout<<dp[c]<<endl;

    }

    return 0;
}
/*
1
8 2
2 100 4
4 100 2
*/
