#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N = 200+5;
const int inf = 99999999;
int edge[N][N],path[N],n,m,l,k,d,minLen=inf,c1,c2;
int res;
map<int,int> Map;
int main()
{
    cin>>n>>m;
    fill(edge[0],edge[0]+N*N,-1);
    for(int i=1;i<=m;i++){
        cin>>c1>>c2>>d;
        edge[c1][c2] = edge[c2][c1] = d;
    }
    cin>>l;
    for(int i=1;i<=l;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>path[j];
        }
        bool isCycle = true;
        bool isExist = true;
        if(path[1]!=path[k])
            isCycle = false;
        int curLen = 0;
        for(int j=1;j<=k-1;j++){
            if(edge[path[j]][path[j+1]]!=-1)
                curLen+=edge[path[j]][path[j+1]];
            else{
                isExist=false;
                break;
            }

        }
        if(!isExist){
            cout<<"Path "<<i<<": NA (Not a TS cycle)"<<endl;
        }
        else{
            int curSum=0;
            for(int j=1;j<=k-1;j++)
                curSum+=edge[path[j]][path[j+1]];

            Map.clear();
            for(int j=1;j<=k;j++){
                Map[path[j]]=1;
            }
            if(Map.size()==n&&isCycle){
                if(k==n+1)
                    cout<<"Path "<<i<<": "<<curSum<<" (TS simple cycle)"<<endl;
                else
                    cout<<"Path "<<i<<": "<<curSum<<" (TS cycle)"<<endl;
                if(curSum<minLen){
                    minLen = curSum;
                    res = i;
                }
            }
            else{
                cout<<"Path "<<i<<": "<<curSum<<" (Not a TS cycle)"<<endl;
            }
        }
    }

    cout<<"Shortest Dist("<<res<<") = "<<minLen<<endl;

    return 0;
}
/*
6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
7
7 5 1 4 3 6 2 5
7 6 1 3 4 5 2 6
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 2 5 4 3 1
7 6 3 2 5 4 1 6
*/
