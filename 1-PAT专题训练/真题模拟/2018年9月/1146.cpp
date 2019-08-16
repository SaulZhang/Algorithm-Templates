#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 1000+5;
int indegree[N]={0},tmpdegree[N],n1,n2,k,A[N];
set<int> S,Stmp;
vector<int> Vec[N],res;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>n1>>n2;
        Vec[n1].push_back(n2);
        indegree[n2]++;
    }
    for(int i=1;i<=n;i++)
        if(indegree[i]==0)
            S.insert(i);
    cin>>k;
    for(int l=0;l<k;l++){
        Stmp = S;
        for(int i=1;i<=n;i++)
            tmpdegree[i]=indegree[i];
        for(int i=1;i<=n;i++) cin>>A[i];
        int cnt=0,idx=1;
        while(!Stmp.empty()){
            if(Stmp.find(A[idx])!=Stmp.end()){
//                cout<<A[idx]<<" exist"<<endl;
                cnt++;
                Stmp.erase(A[idx]);
                for(int i=0;i<Vec[A[idx]].size();i++){
                    tmpdegree[Vec[A[idx]][i]]--;
                    if(tmpdegree[Vec[A[idx]][i]]==0)
                        Stmp.insert(Vec[A[idx]][i]);
                }
            }
            else{
//                cout<<A[idx]<<" not exist"<<endl;
                break;
            }
            idx++;
        }
        if(cnt!=n){
            res.push_back(l);
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1)
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
/*
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6
*/
