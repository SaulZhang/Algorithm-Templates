#include <iostream>
#include <set>
using namespace std;
const int N = 10000+5;
int edge[N][2];
int n,m,n1,n2,k,nv,x;
set<int> S;
bool check(int m){
    for(int i=0;i<m;i++){
        if(S.find(edge[i][0])==S.end()&&S.find(edge[i][1])==S.end()){
            return false;
        }

    }
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>n1>>n2;
        edge[i][0]=n1;
        edge[i][1]=n2;
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>nv;
        S.clear();
        for(int j=1;j<=nv;j++){
            cin>>x;
            S.insert(x);
        }
        if(check(m))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
*/
