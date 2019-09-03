#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string>Vec;
int n;
bool cmp(string a,string b){
    return a+b<b+a;
}
int main()
{
    cin>>n;
    Vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>Vec[i];
    }
    sort(Vec.begin(),Vec.end(),cmp);
    for(int i=0;i<n;i++)
        cout<<Vec[i]<<" ";
    cout<<endl;
    string ans="";
    for(int i=0;i<n;i++)
        ans+=Vec[i];
    while(ans[0]=='0')
        ans.erase(ans.begin());
    if(ans.size()==0)
        cout<<0<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
