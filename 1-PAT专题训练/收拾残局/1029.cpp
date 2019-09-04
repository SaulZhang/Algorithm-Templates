#include <iostream>
using namespace std;
const int N = 1e6+5;
long long A1[N],A2[N],A[N];
int n1,n2,x;
int main()
{
    scanf("%d",&n1);
    for(int i=1;i<=n1;i++)scanf("%lld",&A1[i]);
    scanf("%d",&n2);
    for(int i=1;i<=n2;i++)scanf("%lld",&A2[i]);
    int idx1=1,idx2=1,loc=1;
    while(idx1<=n1&&idx2<=n2){
        if(A1[idx1]<A2[idx2]){
            A[loc++]=A1[idx1++];
        }
        else{
            A[loc++]=A2[idx2++];
        }
    }
    while(idx1<=n1){A[loc++]=A1[idx1++];}
    while(idx2<=n2){A[loc++]=A2[idx2++];}
    printf("%lld",A[(n1+n2+1\)/2]);
    return 0;
}
/*
4 11 12 13 14
5 9 10 15 16 17
*/
