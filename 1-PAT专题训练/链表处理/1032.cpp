#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 1e5+5;
struct Node{
    char c;int next;
};
int n,add1,add2,add,Next;
char c;
vector<Node> Vec;
unordered_map<int,bool> Vis;
int main()
{
    scanf("%d%d%d",&add1,&add2,&n);
    Vec.resize(N);
    for(int i=1;i<=n;i++){
        scanf("%d %c %d",&add,&c,&Next);//当有多种类型数据时，注意占位符中的空格，不能用scanf("%d%c%d",&add,&c,&Next);
        Vec[add] = Node{c,Next};
    }
    for(int i=add1;i!=-1;i = Vec[i].next) Vis[i]=true;
    for(int i=add2;i!=-1;i = Vec[i].next){
        if(Vis[i]){
            printf("%05d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
