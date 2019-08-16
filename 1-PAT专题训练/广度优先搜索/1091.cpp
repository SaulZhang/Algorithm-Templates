//这道题得特别注意输入的顺序，不要想当然

#include <iostream>
#include <queue>
using namespace std;
const int M = 1286+5;
const int N = 128+5;
const int L = 60+5;
int A[M][N][L],n,m,l,t,Ans=0;
int dir[6][3]={{1,0,0},
                {-1,0,0},
                {0,1,0},
                {0,-1,0},
                {0,0,1},
                {0,0,-1}};
bool mark[M][N][L];
struct Node{
    int x,y,z;
    Node(int _x,int _y,int _z){x=_x,y=_y,z=_z;}
};
queue<Node> Que;
int main()
{
    cin>>m>>n>>l>>t;
    for(int i = 1; i <= l; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 1; k <= n; k++)
               cin>>A[j][k][i],mark[i][j][k]=false;
    int curNum=0;
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= n; k++){
                if(A[j][k][i]==1&&!mark[j][k][i]){
                    curNum=1;
                    Que.push(Node(j,k,i));mark[j][k][i]=true;
                    while(!Que.empty()){
                        Node tmp = Que.front();
                        Que.pop();
                        for(int p=0;p<6;p++){
                            int newx = tmp.x+dir[p][0];
                            int newy = tmp.y+dir[p][1];
                            int newz = tmp.z+dir[p][2];
                            if(1<=newx&&newx<=m&&1<=newy&&newy<=n&&1<=newz&&newz<=l
                                      &&!mark[newx][newy][newz]&&A[newx][newy][newz]==1){
                                Que.push(Node(newx,newy,newz));
                                mark[newx][newy][newz]=true;
                                curNum++;
                            }
                        }
                    }
                    if(curNum>=t)
                        Ans+=curNum;
                }
            }
        }
    }
    cout<<Ans<<endl;
    return 0;
}
/*
3 4 5 2

1 1 1 1
1 1 1 1
1 1 1 1

0 0 1 1
0 0 1 1
0 0 1 1

1 0 1 1
0 1 0 0
0 0 0 0

1 0 1 1
0 0 0 0
0 0 0 0

0 0 0 1
0 0 0 1
1 0 0 0
*/
