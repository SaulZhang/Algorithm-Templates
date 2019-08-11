/*
这类题型得多做，现在感觉还没有完全地消化，特别是细节部分
*/
#include <iostream>
#include <vector>
using namespace std;
const int N = 30+5;
int n,pre[N],post[N];
vector<int> In;
bool isUnique=true;
void build(int prSt,int prEd,int poSt,int poEd){
    if(prSt==prEd){//只有一个元素的时候，直接记录该结点的值
        In.push_back(pre[prSt]);
        return;
    }
    if(pre[prSt]==post[poEd]){//当先序遍历的第一个元素与后序遍历的最后一个元素相等的时候再继续
        int idxPre=prSt;
        while(idxPre<=prEd&&pre[idxPre]!=post[poEd-1])idxPre++;//找到post中第poEd-1个元素在pre中的位置
        if(idxPre-prSt==1)//如果post中第poEd-1个元素与pre中第prSt+1个元素相等，那么此时无法区分左右子树
            isUnique=false;
        //开始构建左子树和右子树。
        build(prSt+1,idxPre-1,poSt,poSt+(idxPre-prSt-1)-1);
        In.push_back(pre[prSt]);//中序遍历
        build(idxPre,prEd,poSt+(idxPre-prSt-1),poEd-1);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>pre[i];
    for(int i=0;i<n;i++)cin>>post[i];
    build(0,n-1,0,n-1);
    isUnique==true?cout<<"Yes"<<endl:cout<<"No"<<endl;
    for(int i=0;i<In.size();i++){
        cout<<In[i];
        if(i!=In.size()-1)
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
/*
7
1 2 3 4 6 7 5
2 6 7 4 5 3 1
4
1 2 3 4
2 4 3 1
*/
