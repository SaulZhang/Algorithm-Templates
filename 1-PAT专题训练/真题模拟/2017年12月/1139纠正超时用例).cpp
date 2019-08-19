#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int N = 300 +5;

struct Item{
    int p1,p2;
    Item(int _p1,int _p2){p1 = _p1,p2=_p2;}
    bool operator<(const Item&x)const{
        if(p1!=x.p1){
            return p1<x.p1;
        }
        else{
            return p2<x.p2;
        }
    }
};

int n,m,k,loc=0;
string p1,p2;
unordered_map<string,int>Id2No;
unordered_map<int,string>No2Id;
unordered_map<int,unordered_map<int,bool>> IsFri;
vector<int> Vec[N];//存储每个人的同性朋友
vector<Item> Ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>p1>>p2;
        if(Id2No.count(p1)==0)
            Id2No[p1]=loc,No2Id[loc]=p1,loc++;
        if(Id2No.count(p2)==0)
            Id2No[p2]=loc,No2Id[loc]=p2,loc++;
        if(p1.size()==p2.size()){//同性朋友
            Vec[Id2No[p1]].push_back(Id2No[p2]);
            Vec[Id2No[p2]].push_back(Id2No[p1]);
        }
        IsFri[Id2No[p1]][Id2No[p2]]=true;
        IsFri[Id2No[p2]][Id2No[p1]]=true;
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>p1>>p2;
        Ans.clear();
        if(Id2No.count(p1)!=0&&Id2No.count(p2)!=0)//首先这两个人必须存在
        for(int j=0;j<Vec[Id2No[p1]].size();j++){
            for(int k=0;k<Vec[Id2No[p2]].size();k++){
                string f1 = No2Id[Vec[Id2No[p1]][j]];
                string f2 = No2Id[Vec[Id2No[p2]][k]];
                if(p2!=f1&&p1!=f2&&IsFri[Vec[Id2No[p1]][j]][Vec[Id2No[p2]][k]]){
                    if(f1.size()==5&&f2.size()==5){
                        Ans.push_back(Item(stoi(f1.substr(1,4)),stoi(f2.substr(1,4))));
                    }
                    else if(f1.size()==5){
                        Ans.push_back(Item(stoi(f1.substr(1,4)),stoi(f2)));
                    }
                    else if(f2.size()==5){
                        Ans.push_back(Item(stoi(f1),stoi(f2.substr(1,4))));
                    }
                    else{
                        Ans.push_back(Item(stoi(f1),stoi(f2)));
                    }
                }

            }
        }
        sort(Ans.begin(),Ans.end());
        cout<<Ans.size()<<endl;
        for(int i=0;i<Ans.size();i++){
            printf("%04d %04d\n",Ans[i].p1,Ans[i].p2);
        }

    }
    return 0;
}
