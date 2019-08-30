#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;
unordered_map<string,set<int>> Ma;
int n,m,cId,k;
string name;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>cId>>k;
        for(int j=1;j<=k;j++){
            cin>>name;
            Ma[name].insert(cId);
        }
    }
    for(int i=1;i<=n;i++){
        cin>>name;
        cout<<name<<" "<<Ma[name].size();
        for(auto it=Ma[name].begin();it!=Ma[name].end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
    }
    return 0;
}
