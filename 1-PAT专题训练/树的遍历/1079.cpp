#include <iostream>
#include <vector>
using namespace std;
const int N = 100000+5;
vector<int>Vec[N];
int n,k,ch,Num[N];
double p,r,curSum,totalSum=0;
void dfs(int x){
    if(Vec[x].size()==0)
        totalSum+=(curSum*Num[x]);
    curSum*=(1+r/100);//放在出口的后面是因为，一条边乘一次，而不是一个结点乘一次
    for(int i=0;i<Vec[x].size();i++)
        dfs(Vec[x][i]);
    curSum/=(1+r/100);
}
int main()
{
    cin>>n>>p>>r;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k!=0)
            for(int j=0;j<k;j++){
                cin>>ch;Vec[i].push_back(ch);
            }
        else
            cin>>Num[i];
    }
    curSum = p;
    dfs(0);
    printf("%.1f\n",totalSum);
    return 0;
}
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
*/
