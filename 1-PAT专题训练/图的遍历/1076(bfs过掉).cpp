#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1000+5;
vector<int> Vec[N];
int n,l,k,mark[N],pa,ans=0,m,x;
struct Node{
    int n;int layer;
    Node(int _n,int _l){n=_n;layer=_l;}
};
queue<Node> Que;
int main()
{
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>pa;Vec[pa].push_back(i);
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>x;
        fill(mark+1,mark+1+n,0);
        ans=0;Que.push(Node(x,0));mark[x]=1;
        while(!Que.empty()){
            Node tmp = Que.front();
            Que.pop();
            int tmp_x = tmp.n,tmp_l = tmp.layer;
            if(tmp_l>=1&&tmp_l<=l)
                ans++;
            for(int i=0;i<Vec[tmp_x].size();i++){
                if(mark[Vec[tmp_x][i]]==0){
                    Que.push(Node(Vec[tmp_x][i],tmp_l+1));
                    mark[Vec[tmp_x][i]]=1;//必须在进队的时候进行标记，不能等到出队的时候再标记，不然会导致重复进队
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
*/
