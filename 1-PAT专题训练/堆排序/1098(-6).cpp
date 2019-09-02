#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int>Vec,res;
void getLevelOrder(int st,int ed,int idx){
    if(st>ed)return;
    int n = ed - st + 1;//注意这里的n为当前子树的结点个数，n不能声明为全局变量。
    int l = log2(n+1);
    int leaf = n - (pow(2,l)-1);
    int rootIdx = st+(pow(2,l-1)-1)+min((int)pow(2,l-1),leaf);
    res[idx] = Vec[rootIdx];
    getLevelOrder(st,rootIdx-1,2*idx+1);
    getLevelOrder(rootIdx+1,ed,2*idx+2);
}
int main()
{
    int n;
    cin>>n;
    Vec.resize(n);res.reserve(n);
    for(int i=0;i<n;i++) cin>>Vec[i];
    sort(Vec.begin(),Vec.end());
    getLevelOrder(0,n-1,0);
    for(int i=0;i<n;i++){
        cout<<res[i];
        if(i!=n-1) cout<<" ";
    }
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 0
*/
