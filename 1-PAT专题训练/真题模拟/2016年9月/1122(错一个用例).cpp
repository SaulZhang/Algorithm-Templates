#include <iostream>
#include <map>
using namespace std;
const int N = 200+5;
map<int,map<int,int>> Ma;
int Path[N][N],n,m,k,n1,n2,Node[N],p;
bool check(int p){
    Ma.clear();
    if(Node[0]!=Node[p-1])
        return false;
    for(int i=1;i<p;i++){
        Ma[Node[i-1]][Node[i]]++;
        Ma[Node[i]][Node[i-1]]++;
        if(Path[Node[i-1]][Node[i]]!=1)
            return false;
    }
    if(Ma.size()!=n)
        return false;
    else{
        for(auto it=Ma.begin();it!=Ma.end();it++)
            for(auto it1=it->second.begin();it1!=it->second.end();it1++){
                if(Ma[it->first][it1->first]!=1)
                    return false;
            }

    }
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>n1>>n2;
        Path[n1][n2]=Path[n2][n1]=1;
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        bool flag=true;
        cin>>p;
        for(int j=0;j<p;j++)
            cin>>Node[j];
        if(check(p))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
