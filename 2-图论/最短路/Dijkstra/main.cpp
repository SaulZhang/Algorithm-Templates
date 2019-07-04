/*
hdu 3790
采用Dijkstra+堆优化+链式前向星存储
*/
#include <iostream>
#include <vector>
#include <queue>

#define MaxInt 0x3f3f3f

using namespace std;

const int N = 1001;
const int M = 100001;

struct Node{
    int city;
    int dis;
    int cost;
    Node(int _city,int _dis,int _cost){
        city = _city;
        dis = _dis;
        cost = _cost;
    }
    operator<(const Node &x)const{
        if(x.dis!=dis)
            return dis>x.dis;//小顶堆
        else
            return cost>x.cost;
    }
};

int n,m;
int dis[N],vis[N],pri[N];

vector<Node> Vec[N];
priority_queue<Node> Que;

int main()
{
    int s,t;
    int a,b,d,p;

    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)
            break;
        while(!Que.empty())
            Que.pop();
        for(int i=1;i<=n;i++)
            Vec[i].clear();

        for(int i=1;i<=n;i++){
            dis[i] = MaxInt,vis[i]=0,pri[i]=0;
        }

        for(int i=0;i<m;i++){
            cin>>a>>b>>d>>p;
            Vec[a].push_back(Node(b,d,p));
            Vec[b].push_back(Node(a,d,p));
        }

        cin>>s>>t;

        dis[s] = 0;
        pri[s] = 0;

        //dijksra
        Que.push(Node(s,dis[s],pri[s]));

        while(!Que.empty()){
                Node u = Que.top();
                Que.pop();

                if(vis[u.city]==1)
                    continue;

                vis[u.city]=1;

                for(int j=0;j<Vec[u.city].size();j++){
                    int c = Vec[u.city][j].city;
                    int d = Vec[u.city][j].dis;
                    int p = Vec[u.city][j].cost;

                    if(vis[c]==1)
                        continue;

                    if(dis[c]==dis[u.city]+d){
                        if(pri[c]>pri[u.city]+p){
                            dis[c] = dis[u.city]+d;
                            pri[c] = pri[u.city]+p;
                            Que.push(Node(c,dis[c],pri[c]));
                        }
                    }
                    else if(dis[c]>dis[u.city]+d){
                            dis[c] = dis[u.city]+d;
                            pri[c] = pri[u.city]+p;
                            Que.push(Node(c,dis[c],pri[c]));
                    }
                }
            }

        cout<<dis[t]<<" "<<pri[t]<<endl;
    }
    return 0;
}

/*
3 2
1 2 5 6
2 3 4 5
1 3
4 4
1 2 3 2
2 4 4 1
1 3 4 4
3 4 3 3
1 4
0 0
*/
