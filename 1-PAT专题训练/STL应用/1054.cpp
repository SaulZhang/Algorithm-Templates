#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,x;
vector<int>Vec;
unordered_map<int,int> Ma;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            if(Ma.count(x)==0)
                Vec.push_back(x);
            Ma[x]++;
        }
    }
    int maxNum=0,ans;
    for(int i=0;i<Vec.size();i++){
        if(Ma[Vec[i]]>maxNum)
            maxNum = Ma[Vec[i]],ans=Vec[i];

    }
    cout<<ans<<endl;
    return 0;
}
