/*坑点1:存在不在链表中的结点*/
/*坑点2:存在空节点，必须输出0 -1*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
    int head,data,next;
}node[100000+5];
bool cmp(Node a,Node b){
    return a.data<b.data;
}
vector<Node>Vec;
int n,st;
int add,c,Next;
int main()
{
    scanf("%d %d",&n,&st);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&add,&c,&Next);
        node[add] = Node{add,c,Next};
    }
    if(st!=-1)//先判断一下起始点是否为空
        for(int i=st;i!=-1;i=node[i].next)//取出在链表中的结点
            Vec.push_back(Node{i,node[i].data,node[i].next});
    sort(Vec.begin(),Vec.end(),cmp);
    if(Vec.size()>=1){
        printf("%d %05d\n",Vec.size(),Vec[0].head);
        for(int i=0;i<Vec.size()-1;i++)printf("%05d %d %05d\n",Vec[i].head,Vec[i].data,Vec[i+1].head);
        printf("%05d %d -1\n",Vec[Vec.size()-1].head,Vec[Vec.size()-1].data);
    }
    else{
        printf("0 -1\n");
    }
    return 0;
}
