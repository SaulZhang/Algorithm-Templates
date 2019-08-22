#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
unordered_map<int,int>Ma;
set<int> S;
int main()
{
    int n,m,c1,c2,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c1>>c2;
        Ma[c1]=c2;
        Ma[c2]=c1;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        if(Ma.count(x)!=0&&S.find(Ma[x])!=S.end()){
            S.erase(Ma[x]);
        }
        else{
            S.insert(x);
        }
    }
    cout<<S.size()<<endl;
    int cnt=0;
    for(auto it=S.begin();it!=S.end();it++){
        printf("%05d",*it);cnt++;
        if(cnt==S.size())
            cout<<endl;
        else
            cout<<" ";
    }
    return 0;
}
