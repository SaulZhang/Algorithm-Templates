#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,l;
map<string,int> Ass;
map<string,int> Mid;
map<string,int> Fin;
string str;
int score;
struct Item{
    string id;
    int as_score;
    int mid_score;
    int fin_score;
    int tot_score;
    Item(string _id,int _as_score,int _mid_score,int _fin_score,int _tot_score){
        id = _id;
        as_score=_as_score;
        mid_score=_mid_score;
        fin_score=_fin_score;
        tot_score=_tot_score;
    }
    bool operator<(const Item&x)const{
        if(tot_score!=x.tot_score){
            return tot_score>x.tot_score;
        }
        else{
            return id<x.id;
        }
    }
};
vector<Item>Vec;
int main()
{
    cin>>n>>m>>l;
    for(int i=1;i<=n;i++){
        cin>>str>>score;Ass[str] = score;
    }
    for(int i=1;i<=m;i++){
        cin>>str>>score;Mid[str] = score;
    }
    for(int i=1;i<=l;i++){
        cin>>str>>score;Fin[str] = score;
    }
    int ass,mids,fins,tots;
    for(auto it=Ass.begin();it!=Ass.end();it++){
        if(it->second>=200&&Fin[it->first]>=60&&Fin[it->first]<=100){
            ass = it->second;
            if(Mid.count(it->first)==0)
                mids = -1;
            else
                mids = Mid[it->first];
            fins = Fin[it->first];
            if(mids>fins)
                tots = round(mids*0.4+fins*0.6);
            else
                tots = fins;
            Vec.push_back(Item(it->first,ass,mids,fins,tots));
        }
    }
    sort(Vec.begin(),Vec.end());
    for(int i=0;i<Vec.size();i++){
        cout<<Vec[i].id<<" "<<Vec[i].as_score<<" "<<Vec[i].mid_score<<" "<<Vec[i].fin_score<<" "<<Vec[i].tot_score<<endl;
    }
    return 0;
}
/*
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
*/
