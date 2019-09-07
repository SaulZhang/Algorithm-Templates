#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100+5;
vector<int> Vec[N],tmppath;
int n,m,Sum,id,k,ch,Weight[N],curSum=0;
bool cmp(int a,int b){return Weight[a]>Weight[b];}
void dfs(int x){
    tmppath.push_back(Weight[x]);
    curSum+=Weight[x];
    if(Vec[x].size()==0&&curSum==Sum){
        for(int i=0;i<tmppath.size();i++){
            cout<<tmppath[i];
            if(i!=tmppath.size()-1)cout<<" ";
            else cout<<endl;
        }
    }
    for(int i=0;i<Vec[x].size();i++) dfs(Vec[x][i]);
    tmppath.pop_back();
    curSum-=Weight[x];
}
int main()
{
    cin>>n>>m>>Sum;
    for(int i=0;i<n;i++)cin>>Weight[i];
    for(int i=0;i<m;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            cin>>ch;
            Vec[id].push_back(ch);
        }
    }
    for(int i=0;i<n;i++) sort(Vec[i].begin(),Vec[i].end(),cmp);
    dfs(0);
    return 0;
}
