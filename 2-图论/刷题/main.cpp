/*
hdu 4318
��ʽǰ����:
*/
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define M 50*50000
#define N 50000

using namespace std;

double dis[N];//ά�����ﵱǰ������ʧ
bool mark[N];
int head[N];//head[i]��ʾ���Ϊi�Ľ�����ܵ���ı�����Ľ�� ��Ӧ�ıߵı��

double Power,cost;
int n,m,toNode,s,t,tot=0;

struct Edge{
    int next;//����ͬ���ıߵı��
    int to;//�ñߵ���ֹ��ı��
    double w;//�ñ������е�Ȩ��
}edge[M];

struct Node{
    int id;
    double loss;
    Node() {}
    Node(int x,double y){
        id = x;
        loss = y;
    }
    bool operator < (const Node &r)const{
        return loss < r.loss;
    }
};

priority_queue<Node> Que;

void add_Edge(int u,int v,int w){
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}

void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}

void Dijkstra(int s,int t){

    //��ʼ������
    memset(dis,0,sizeof(dis));
    memset(mark,false,sizeof(mark));

    while (!Que.empty())
        Que.pop();

    dis[s]=Power;
    Que.push(Node(s,Power));

    while(!Que.empty()){

        int u = Que.top().id;
        Que.pop();

        if(mark[u])
            continue;

        mark[u]=true;

        if(u==t)
            break;

        for(int i=head[u];~i;i=edge[i].next){
            if(dis[edge[i].to] < dis[u]*(1-edge[i].w/100.)){
                dis[edge[i].to] = dis[u]*(1-edge[i].w/100.);//ά����ǰ��ʣ����
                Que.push(Node(edge[i].to,dis[edge[i].to]));
            }
        }

    }

}


int main()
{

    ios::sync_with_stdio(false);//�ر�C++��C����
    cin.tie(0);//���cin��cout֮��İ�

    while(~scanf("%d",&n)){

        init();

        for(int i=1;i<=n;i++){
            scanf("%d",&m);
            for(int j=1;j<=m;j++){
                scanf("%d%lf",&toNode,&cost);
                add_Edge(i,toNode,cost);
            }
        }

        scanf("%d%d%lf",&s,&t,&Power);
        Dijkstra(s,t);

        if(mark[t])
            printf("%.2f\n",Power-dis[t]);
        else
            printf("IMPOSSIBLE!\n");

    }
    return 0;
}

/*
4
2
2 50
3 70
2
1 30
4 20
2
1 10
4 40
0
1 4 100
*/
