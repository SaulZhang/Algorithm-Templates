#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n,k,p;
int curVal=0,curSum=0;
bool cmp(int a,int b){return a>=b;}
vector<int> tmpPath,res,curTmp;
int power(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i++){
        ans*=x;
    }
    return ans;
}
void dfs(int x,int dep){//注意根结点是不会弹出去的
    curVal += power(x,p);
    curTmp.push_back(x);
    if(curVal==n&&dep==k){
        tmpPath = curTmp;
        sort(tmpPath.begin(),tmpPath.end(),cmp);
        int tmpSum=0;
        for(int i=0;i<tmpPath.size();i++)
            tmpSum+=tmpPath[i];
        if(res.size()==0){
            res = tmpPath;
            curSum = tmpSum;
        }
        else{
            if(tmpSum>curSum){
                res = tmpPath;
                curSum = tmpSum;
            }
            else if(tmpSum==curSum){
                bool flag=false;
                for(int i=0;i<tmpPath.size();i++){
                    if(tmpPath[i]>res[i]){
                        flag=true;break;
                    }
                    else if(tmpPath[i]==res[i]){
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(flag){
                    res = tmpPath;
                }
            }
        }
    }

    for(int i=x;i<=int(pow(n,1.0/p));i++){
        if(dep<k&&curVal+i<=n){
            dfs(i,dep+1);
        }
    }
    curTmp.pop_back();
    curVal -= power(x,p);
}
int main()
{
    cin>>n>>k>>p;
    for(int i=1;i<=int(sqrt(n));i++)
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
169 5 3
*/
