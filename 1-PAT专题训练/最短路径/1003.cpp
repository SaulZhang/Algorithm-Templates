#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int N = 500+5;
const int inf = 9999999;

int dis[N];
int team[N];
int numPath[N];
int numTeam[N];
bool mark[N];

struct NextEdge{
    int v;
    int c;
    NextEdge(int _v,int _c){
        v = _v;
        c = _c;
    }
};

vector<NextEdge> Vec[N];

int n,m,st,ed;
int c1,c2,L;

int main()
{
    for(int i=0;i<N;i++)
        dis[i]=inf,numTeam[i]=0,numPath[i]=0;

    cin>>n>>m>>st>>ed;

    for(int i=0;i<n;i++)
        cin>>team[i];

    for(int i=0;i<m;i++){
        cin>>c1>>c2>>L;
        Vec[c1].push_back(NextEdge(c2,L));
        Vec[c2].push_back(NextEdge(c1,L));
    }

    int newP = st;
    dis[newP] = 0;
    numTeam[newP] = team[newP];
    mark[newP]  = true;
    numPath[newP]=1;

    int v,c;
    for(int i=1;i<n;i++){
        for(int j=0;j<Vec[newP].size();j++){
            v = Vec[newP][j].v;
            c = Vec[newP][j].c;
            if(!mark[v]){
                if(dis[newP]+c==dis[v]){
                    numPath[v]+=numPath[newP];
                    if(numTeam[newP]+team[v]>numTeam[v])
                        numTeam[v] = numTeam[newP]+team[v];
                }
                else if(dis[newP]+c<dis[v]){
                    numPath[v]=numPath[newP];
                    dis[v] = dis[newP] + c;
                    numTeam[v] = numTeam[newP]+team[v];
                }
            }
        }

        int min_cost = INT_MAX;

        for(int j=0;j<n;j++){
            if(!mark[j]){
                if(min_cost>dis[j]){
                    min_cost = dis[j];
                    newP = j;
                }
            }
        }

        mark[newP]=true;
    }

    cout<<numPath[ed]<<" "<<numTeam[ed]<<endl;

    return 0;

}
/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/
