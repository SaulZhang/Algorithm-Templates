#include <iostream>

#define N 101

using namespace std;

int A[N],L[N];//L数组中用于维护当前长度下整体值尽可能小的 序列

int LIS(int n){

    int pos=0;

    if(n!=0){

        L[0] = A[0];//初始化第一个位置
        for(int i=1;i<n;i++){
            if(A[i]>L[pos]){
                L[++pos] = A[i];
            }
            else{
                int idx = lower_bound(L,L+pos+1,A[i])-L;
                L[idx] = A[i];
            }
        }

    }
    return pos+1;
}


int main()
{
    int n;
    while(~scanf("%d",&n)){

        for(int i=0;i<n;i++)
            cin>>A[i];

        cout<<LIS(n)<<endl;
    }

    return 0;
}
/*

8
1 23 45 5 65 76 87 2


4
6
4
2
6
3
1
5
10
2
3
4
5
6
7
8
9
10
1
8
8
7
6
5
4
3
2
1
9
5
8
9
2
3
1
7
4
6





*/




