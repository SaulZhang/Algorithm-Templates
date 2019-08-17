#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int,map<int,int>> Edge;
int nv,ne,n1,n2,m,l,x,k;
set<int> tmp;
int main()
{
    cin>>nv>>ne;
    for(int i=1;i<=ne;i++){
        cin>>n1>>n2;
        Edge[n1][n2] = Edge[n2][n1] = 1;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>k;
        tmp.clear();
        for(int j=1;j<=k;j++){
            cin>>x;
            tmp.insert(x);
        }
        bool isCli=true,isMax=true;
        for(auto it1=tmp.begin();it1!=tmp.end();it1++){
            for(auto it2=tmp.begin();it2!=tmp.end();it2++){
                if(*it1==*it2)
                    continue;
                else{
                    if(Edge[*it1][*it2]!=1){
                        isCli=false;
                        break;
                    }
                }
            }
            if(!isCli){
                break;
            }
        }

        for(int j=1;j<=nv;j++){
            if(tmp.find(j)==tmp.end()){
                int cnt=0;
                for(auto it=tmp.begin();it!=tmp.end();it++){
                    if(Edge[j][*it]==1)
                        cnt++;
                }
                if(cnt==k){
                    isMax = false;
                    break;
                }
            }
        }
        if(isMax&&isCli)
            cout<<"Yes"<<endl;
        else if(!isMax&&isCli)
            cout<<"Not Maximal"<<endl;
        else
            cout<<"Not a Clique"<<endl;

    }


    return 0;
}
/*
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
*/
