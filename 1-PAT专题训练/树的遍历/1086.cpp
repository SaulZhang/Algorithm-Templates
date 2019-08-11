#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
const int N = 30+5;
vector<int>Vec[N],post;
int n,curNode,Cnt[N]={0},x,root;//数组Cnt[N]用来标记第几次访问当前的结点
string op;
stack<int> S;//用于模拟栈内的状态
void postOrder(int x){
    if(Vec[x][0]!=0)  postOrder(Vec[x][0]);
    if(Vec[x][1]!=0)  postOrder(Vec[x][1]);
    post.push_back(x);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)//初始化二维动态数组
        for(int j=1;j<=2;j++)
            Vec[i].push_back(0);
    cin>>op>>x;//必须为push
    S.push(x);curNode = x;
    Cnt[x]+=1;root = x;
    for(int i=2;i<=2*n;i++){
        cin>>op;
        if(op=="Push"){
            cin>>x;S.push(x);
            if(Cnt[curNode]==1)//curNode第一次访问的话，则该结点为其左子树的根
                Vec[curNode][0]=x;
            else if(Cnt[curNode]==2){//curNode第二次访问的话，则该结点为其右子树的根
                Vec[curNode][1]=x;
            }
            curNode = x;Cnt[x]+=1;
        }
        else if(op=="Pop"){
            curNode = S.top();S.pop();
            Cnt[curNode]+=1;
        }
    }
    postOrder(root);
    for(int i=0;i<post.size();i++){
        cout<<post[i];
        (i!=post.size()-1)?cout<<" ":cout<<endl;
    }
    return 0;
}
/*
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
*/
