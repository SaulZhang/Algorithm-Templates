#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 20+5;
struct Node{
    string data;
    int l,r;
}node[N];
string s1="",ans="";
int li,ri,rootId[N],root=1,n;
string dfs(int x){
    if(node[x].l!=-1&&node[x].r!=-1) return "("+dfs(node[x].l)+node[x].data+dfs(node[x].r)+")";
    else if(node[x].l==-1&&node[x].r!=-1) return "("+node[x].data+dfs(node[x].r)+")";
    else if(node[x].l==-1&&node[x].r==-1) return node[x].data;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s1>>li>>ri;
        rootId[li]++;rootId[ri]++;
        node[i] = {s1,li,ri};
    }
    while(rootId[root]!=0)root++;
    ans = dfs(root);
    ans[0]=='('?cout<<ans.substr(1,ans.size()-2)<<endl:cout<<ans<<endl;
    return 0;
}
