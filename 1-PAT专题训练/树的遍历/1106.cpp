#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
const int N = 100000+5;
const double inf = 1e11;
vector<int> Vec[N];
int n,k,ch,Num=0;
double p,r,curSum,minPri=inf;
double abs(double a){return a>0? a:-1*a;}
void dfs(int x){
    if(Vec[x].size()==0){
        if(curSum<minPri){
            minPri=curSum;Num=1;
        }
        else if(abs(curSum-minPri)<1e-7)
            Num++;
    }
    curSum*=(1+r/100);
    for(int i=0;i<Vec[x].size();i++)
        dfs(Vec[x][i]);
    curSum/=(1+r/100);
}
int main()
{
    cin>>n>>p>>r;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>ch;
            Vec[i].push_back(ch);
        }
    }
    curSum=p;
    dfs(0);
    printf("%.4f %d\n",minPri,Num);
    return 0;
}
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
*/
