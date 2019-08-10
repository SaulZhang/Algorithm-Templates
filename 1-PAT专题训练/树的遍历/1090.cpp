#include <iostream>
#include <vector>
using namespace std;
const int N=100000+5;
vector<int>Vec[N];
int n,pa,root,Num=0;
double p,r,curSum,maxPrice=0;
void dfs(int x){
    if(Vec[x].size()==0){
        if(curSum>maxPrice)
            maxPrice=curSum,Num=1;
        else if(curSum==maxPrice)
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
        cin>>pa;
        if(pa==-1) root=i;
        else Vec[pa].push_back(i);
    }
    curSum = p;
    dfs(root);
    printf("%.2f %d\n",maxPrice,Num);
    return 0;
}
