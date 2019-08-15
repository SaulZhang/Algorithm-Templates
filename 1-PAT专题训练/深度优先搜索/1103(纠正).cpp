#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n,k,p,A[20+5],loc=1,curSum=0,maxSum=0,maxfactorSum=0;
vector<int> tmpPath,res;
int power(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i++) ans*=x;
    return ans;
}
void init(){
    int i=1,tmp=0;
    while(1){
        tmp = power(i,p);
        if(tmp<=n)
            A[loc++]=tmp,i++;
        else
            break;
    }
}
void dfs(int x,int dep){

    tmpPath.push_back(x);
    curSum+=A[x];

    if(curSum==n&&dep==k){
        int tmpFactorSum = 0;
        for(int i=0;i<tmpPath.size();i++)
            tmpFactorSum+=tmpPath[i];
        if(curSum>maxSum){
            maxSum = curSum;res = tmpPath;maxfactorSum = tmpFactorSum;
        }
        else if(curSum==maxSum&&tmpFactorSum>maxfactorSum){
            res = tmpPath;maxfactorSum = tmpFactorSum;
        }
    }

    for(int i=x;i>=1;i--){
        if(dep<k&&curSum+A[i]<=n)
            dfs(i,dep+1);
    }
    curSum-=A[x];
    tmpPath.pop_back();
}
int main()
{
    cin>>n>>k>>p;
    init();
    for(int i=loc-1;i>=1;i--)
        dfs(i,1);
    if(res.size()==0)
        cout<<"Impossible"<<endl;
    else{
        cout<<n<<" = ";
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<"^"<<p;
            if(i!=res.size()-1)
                cout<<" + ";
            else
                cout<<endl;
        }
    }
    return 0;
}
/*
169 5 2
*/
