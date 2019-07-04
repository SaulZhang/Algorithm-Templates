#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

int tot=0;

int head[101];

int Indegree[101];

void init(){
    memset(head,-1,sizeof(head));
    memset(Indegree,0,sizeof(Indegree));
    tot=0;
}

struct Edge{
    int to;
    int next;
}edge[101];

void addEdge(int u,int v){

    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

queue<int> Que;

int main()
{
    init();
    int u = 1;
    int n,m,a,b,c,sum=0;
    cin>>n>>m;
    while(!Que.empty())Que.pop();
    for(int i=0;i<m;i++){
       cin>>a>>b;
       addEdge(a,b);
       Indegree[b]++;
    }
    for(int i=1;i<n;i++)
        if(Indegree[i]==0)
            Que.push(i);

    while(!Que.empty()){
        int u = Que.front();
        cout<<u<<endl;
        sum++;
        Que.pop();
        for(int i=head[u];~i;i=edge[i].next){
            Indegree[edge[i].to]--;
            if(Indegree[edge[i].to]==0)
                Que.push(edge[i].to);
        }
    }

    cout<<"The sum is:"<<sum<<endl;


    return 0;
}
/*
5 8

1 2
1 4
1 5
2 5
5 4
2 3
4 3
3 5
*/
