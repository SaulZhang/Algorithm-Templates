/*
采用并查集思想来实现每个团体的合并，还有一个用例没过..扣了3分
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int N = 2000+5;
int n,k,Num[N],W_Node[N]={0},W_Gang[N]={0},len,w[N],loc=0,Tree[N];
vector<int>Vec[N],ans;
string str[N][2];
map<string,int>Name2id;
map<int,string>Id2name;
struct Item{
    string s;
    int num;
    Item(string _s,int _num){
        s =_s;
        num = _num;
    }
    bool operator<(const Item &x)const{
        return s<x.s;
    }
};
vector<Item> headName;
int findRoot(int x){
    if(Tree[x]==-1)
        return x;
    else
        return Tree[x]=findRoot(Tree[x]);
}
int main()
{
    fill(Num,Num+N,1);
    fill(Tree,Tree+N,-1);
    cin>>n>>k;
    for(int i=0;i<n;i++){//name to id
        cin>>str[i][0]>>str[i][1]>>w[i];
        if(Name2id.count(str[i][0])==0){
            Name2id[str[i][0]]=loc;
            Id2name[loc]=str[i][0];
            loc++;
        }
        if(Name2id.count(str[i][1])==0){
            Name2id[str[i][1]]=loc;
            Id2name[loc]=str[i][1];
            loc++;
        }
        W_Node[Name2id[str[i][0]]]+=w[i];
        W_Node[Name2id[str[i][1]]]+=w[i];
    }
    for(int i=0;i<loc;i++)
        Vec[i].push_back(i);//把自己加入以自己为根的集合中

    for(int i=0;i<n;i++){
        int rootA = findRoot(Name2id[str[i][0]]);
        int rootB = findRoot(Name2id[str[i][1]]);
        if(rootA!=rootB){
            Tree[rootB]=rootA;
            for(int j=0;j<Vec[rootB].size();j++)
                Vec[rootA].push_back(Vec[rootB][j]),Vec[rootB].clear();//成员合并
            W_Gang[rootA]+=(W_Gang[rootB]+w[i]);//更新团伙总权重
            Num[rootA]+=Num[rootB];//更新集合大小
            Num[rootB]=0;
        }
        else
            W_Gang[rootA]+=w[i];//已经是一个集合了，但是这条边的权重也要加上。
    }
    for(int i=0;i<loc;i++){
        if(Num[i]>2&&W_Gang[i]>k)
            ans.push_back(i);
    }
    for(int i=0;i<ans.size();i++){
        int maxW=0,idx=-1;
        for(int j=0;j<Vec[ans[i]].size();j++){
            if(W_Node[Vec[ans[i]][j]]>maxW){
                maxW = W_Node[Vec[ans[i]][j]];
                idx = Vec[ans[i]][j];
            }
        }
        headName.push_back(Item(Id2name[idx],Num[ans[i]]));
    }
    sort(headName.begin(),headName.end());
    cout<<headName.size()<<endl;
    for(int i=0;i<headName.size();i++)
        cout<<headName[i].s<<" "<<headName[i].num<<endl;

    return 0;
}
/*
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/
