#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,k,p1,p2;
map<int,map<int,bool>> Ma;
struct Item{
    int p1,p2;
    Item(int _p1,int _p2){p1 = _p1,p2=_p2;}
    bool operator<(const Item&x)const{
        if(p1!=x.p1){
            return p1<x.p1;
        }
        else{
            return p2<x.p2;
        }
    }
};
vector<Item>Ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>p1>>p2;
        Ma[p1][p2] = Ma[p2][p1] = true;
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        Ans.clear();
        cin>>p1>>p2;
        for(auto it = Ma.begin();it!=Ma.end();it++){
            for(auto it1 = it->second.begin();it1!=it->second.end();it1++){
                if(Ma[p1][it->first]&&Ma[p2][it1->first]
                   &&it->first!=it1->first&&p1*it->first>0
                   && p2*it1->first>0 && p1!=it->first&& p2!=it1->first){
                    Ans.push_back(Item(abs(it->first),abs(it1->first)));
                }
            }
        }
        sort(Ans.begin(),Ans.end());
        cout<<Ans.size()<<endl;
        for(int i=0;i<Ans.size();i++){
            cout<<Ans[i].p1<<" "<<Ans[i].p2<<endl;
        }
    }
    return 0;
}
/*
10 18
-2001 1001
-2002 -2001
1004 1001
-2004 -2001
-2003 1005
1005 -2001
1001 -2003
1002 1001
1002 -2004
-2004 1001
1003 -2002
-2003 1003
1004 -2002
-2001 -2003
1001 1003
1003 -2001
1002 -2001
-2002 -2003
5
1001 -2001
-2003 1001
1005 -2001
-2002 -2004
1111 -2003


10 18
-2001 1001
-2002 -2001
1004 1001
-2004 -2001
-2003 1005
1005 -2001
1001 -2003
1002 1001
1002 -2004
-2004 1001
1003 -2002
-2003 1003
1004 -2002
-2001 -2003
1001 1003
1003 -2001
1002 -2001
-2002 -2003
5
1005 -2001
*/
