#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int n;
vector<int>Vec,res,lowb,uppb;

int main()
{
    cin>>n;
    Vec.resize(n);
    lowb.resize(n);
    uppb.resize(n);
    for(int i=0;i<n;i++)
        cin>>Vec[i];
    int curMin=INT_MAX,curMax=INT_MIN;
    for(int i=0;i<n;i++){
        uppb[i] = curMax;
        curMax=max(curMax,Vec[i]);
    }
    for(int i=n-1;i>=0;i--){
        lowb[i] = curMin;
        curMin=min(curMin,Vec[i]);
    }
    for(int i=0;i<n;i++){
        if(Vec[i]>uppb[i]&&Vec[i]<lowb[i])
            res.push_back(Vec[i]);
    }
    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1) cout<<" ";
    }
    return 0;
}
/*
5
1 3 2 4 5
*/
