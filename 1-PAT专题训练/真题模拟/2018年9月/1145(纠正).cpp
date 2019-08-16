//参考：https://blog.csdn.net/qq_34594236/article/details/79814881
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 10000+200;
int Hash[N],TSize,n,m,x,totSearch=0;
bool isPrime(int x){
    int up = sqrt(x)+1;
    for(int i=2;i<up;i++)
        if(x%i==0)
            return false;
    return true;
}

int main()
{
    fill(Hash,Hash+N,-1);
    cin>>TSize>>n>>m;
    while(!isPrime(TSize))
        TSize++;
    int pos=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        bool flag=false;
        for(int j=0;j<TSize;j++){
            pos = (x%TSize + j*j)%TSize;
            if(Hash[pos]==-1){
                flag=true;
                Hash[pos] = x;break;
            }
        }
        if(!flag)
            cout<<x<<" cannot be inserted."<<endl;
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        pos=0;
        bool flag=false;
        for(int j=0;j<TSize;j++){
            totSearch++;
            pos = (x%TSize + j*j)%TSize;
            if(Hash[pos]==x||Hash[pos]==-1){
                flag=true;
                break;
            }
        }
        if(!flag)//这个地方比较迷呐
            totSearch++;
    }
    printf("%.1f",1.0*totSearch/m);
    return 0;
}
/*
4 5 4
10 6 4 15 11
11 4 15 2
*/
