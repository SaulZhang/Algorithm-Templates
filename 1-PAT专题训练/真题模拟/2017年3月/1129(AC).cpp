#include <iostream>
#include <set>
using namespace std;
const int N = 100000+5;
int n,x,k,book[N]={0};
struct Node{
    int val,cnt;
    Node(int _val,int _cnt){val=_val,cnt=_cnt;}
    bool operator<(const Node&x)const{
        return cnt!=x.cnt?cnt>x.cnt:val<x.val;
    }
};
set<Node>S;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i!=1){
            int tmpcnt = 0;
            cout<<x<<":";
            for(auto it=S.begin();it!=S.end()&&tmpcnt<k;it++){
                cout<<" "<<it->val;tmpcnt++;
            }
            cout<<endl;
        }
        auto it = S.find(Node(x,book[x]));
        if(it!=S.end()) S.erase(it);
        book[x]++;
        S.insert(Node(x,book[x]));
    }
    return 0;
}
