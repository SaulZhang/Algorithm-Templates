#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string,vector<string>> p1;
set<string> S;
int n,m,k;
string str1,str2;
bool mark=true;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>str1>>str2;
        p1[str1].push_back(str2);
        p1[str2].push_back(str1);
    }
    for(int i=1;i<=m;i++){
        mark=true;
        S.clear();
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>str1;
            S.insert(str1);
        }
        for(auto it=S.begin();it!=S.end();it++){
            for(int j=0;j<p1[*it].size();j++){
                if(S.find(p1[*it][j])!=S.end()){
                    mark=false;
                    break;
                }
                if(!mark)
                    break;
            }
        }
        if(mark)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
/*
6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333
*/
