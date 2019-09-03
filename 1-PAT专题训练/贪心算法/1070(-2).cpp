#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct MoonCake{
    int inv;
    double pri;
    bool operator<(const MoonCake&x)const{
        return pri/inv>x.pri/x.inv;
    }
};
int n,D;
vector<MoonCake>Vec;
int main()
{
    double ans=0;
    cin>>n>>D;
    Vec.resize(n);
    for(int i=0;i<n;i++){cin>>Vec[i].inv;}
    for(int i=0;i<n;i++){cin>>Vec[i].pri;}
    sort(Vec.begin(),Vec.end());
    int idx=0;
    while(idx<n){
        if(D>Vec[idx].inv){
            ans+=Vec[idx].pri;
            D-=Vec[idx].inv;
        }
        else{
            ans+=Vec[idx].pri*D/Vec[idx].inv;
            break;
        }
        idx++;
    }
    printf("%.2f",ans);
    return 0;
}
