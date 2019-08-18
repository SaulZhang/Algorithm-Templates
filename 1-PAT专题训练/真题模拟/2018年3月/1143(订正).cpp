#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 10000+5;
const int M = 1000+5;
map<int,bool>Ma;
vector<int> pre(N);
int m,n,u,v,res;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        cin>>pre[i],Ma[pre[i]]=true;;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        if(!Ma[u]&&!Ma[v])
            cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
        else if(!Ma[u])
            cout<<"ERROR: "<<u<<" is not found."<<endl;
        else if(!Ma[v])
            cout<<"ERROR: "<<v<<" is not found."<<endl;
        else{
            for(int j=0;j<pre.size();j++){
                res = pre[j];
                if((u<=res&&v>=res)||(u>=res&&v<=res)){
                    break;
                }
            }
            if(res==u)
                cout<<res<<" is an ancestor of "<<v<<"."<<endl;
            else if(res==v)
                cout<<res<<" is an ancestor of "<<u<<"."<<endl;
            else
                cout<<"LCA of "<<u<<" and "<<v<<" is "<<res<<"."<<endl;
        }
    }
    return 0;
}
/*
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99
*/
