#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int N = 100000+5;
struct Node{
    string st,next;
    int data;
    Node(string _st,string _next,int _data){st=_st,next=_next,data=_data;}
};
unordered_map<string,unordered_map<string,int>> Ma;
unordered_map<string,string>Ma1;
int n,k,d;
string st,s1,s2;
vector<Node> tmp,tmp1,tmp2;
bool vis[N];
int main()
{
    cin>>st>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s1>>d>>s2;
        Ma[s1][s2] = d;
        Ma1[s1]=s2;
    }
    int cnt=0;
    s1 = st;
    while(tmp.size()<n){
        tmp.push_back(Node(s1,Ma1[s1],Ma[s1][Ma1[s1]]));
        s1 = Ma1[s1];
    }
    for(int i=0;i<tmp.size();i++){
        if(!vis[i]&&tmp[i].data<0){
            if(tmp1.size()!=0)
                tmp1[tmp1.size()-1].next = tmp[i].st;
            tmp1.push_back(Node(tmp[i].st,tmp[i].next,tmp[i].data));
            vis[i]=true;
        }
    }
    for(int i=0;i<tmp.size();i++){
        if(!vis[i]&&tmp[i].data>=0&&tmp[i].data<=k){
            if(tmp1.size()!=0)
                tmp1[tmp1.size()-1].next = tmp[i].st;
            tmp1.push_back(Node(tmp[i].st,tmp[i].next,tmp[i].data));
            vis[i]=true;
        }
    }
    for(int i=0;i<tmp.size();i++){
        if(!vis[i]){
            if(tmp1.size()!=0)
                tmp1[tmp1.size()-1].next = tmp[i].st;
            tmp1.push_back(Node(tmp[i].st,tmp[i].next,tmp[i].data));
            vis[i]=true;
        }
    }
    if(tmp1.size()!=0)
        tmp1[tmp1.size()-1].next = "-1";

    for(int i=0;i<tmp1.size();i++)
        cout<<tmp1[i].st<<" "<<tmp1[i].data<<" "<<tmp1[i].next<<endl;

    return 0;
}
/*
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
*/
