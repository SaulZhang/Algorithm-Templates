#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int N = 1e3+5;
int loc=0,n,k,num[N]={0};
vector<int>tmp(1000);
set<int> S[N];
int main()
{
    cin>>n;
    while(n--){
        scanf("%d: ",&k);
        for(int i=1;i<=k;i++) cin>>tmp[i];
        bool flag=false;//是否找到组织
        int idx=0;//组织的下标
        for(int i=1;i<=k;i++){//遍历每个爱好
            for(int j=0;j<loc;j++){//遍历每个组织(组织是一个爱好的集合)
                if(S[j].find(tmp[i])!=S[j].end()){
                    flag=true;idx=j;
                    num[j]++;//组织成员+1
                }
            }
        }
        if(flag){//找到组织
            for(int i=1;i<=k;i++) S[idx].insert(tmp[i]);//将当前这个人的爱好注入到对应的组织中
        }
        else{//另辟组织
            for(int i=1;i<=k;i++) S[loc].insert(tmp[i]);
            num[loc]++;loc++;
        }
    }
    cout<<loc<<endl;
    sort(num,num+loc,greater<int>());
    for(int i=0;i<loc;i++){
        cout<<num[i];
        if(i!=loc-1)
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
