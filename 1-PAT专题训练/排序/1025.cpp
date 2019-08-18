#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Local{
    string id;
    int score;
    Local(string _id,int _score){id=_id,score=_score;}
    bool operator<(const Local&x)const{
        return score>x.score;//这一行要是改成score>=x.score会出现段错误，为什么？
    }
};
struct Nation{
    string id;
    int score;
    int location_number;
    int localRank;
    Nation(string _id,int _score,int _location_number,int _localRank){
        id = _id,score = _score,location_number = _location_number,localRank = _localRank;
    }
    bool operator<(const Nation&x)const{
        if(score!=x.score)
            return score>x.score;
        else
            return id<x.id;
    }
};
int n,k,score;
vector<Local> Loc;
vector<Nation> Nat;
string id;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        Loc.clear();
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>id>>score;
            Loc.push_back(Local(id,score));
        }
        sort(Loc.begin(),Loc.end());
        int cnt=0;
        for(int j=0;j<Loc.size();j++){
            if(j==0){
                Nat.push_back(Nation(Loc[j].id,Loc[j].score,i,j+1));
            }
            else{
                if(Loc[j].score==Loc[j-1].score){
                    cnt++;
                    Nat.push_back(Nation(Loc[j].id,Loc[j].score,i,j+1-cnt));
                }
                else{
                    cnt=0;
                    Nat.push_back(Nation(Loc[j].id,Loc[j].score,i,j+1));
                }
            }
        }
    }
    sort(Nat.begin(),Nat.end());
    int cnt=0;
    cout<<Nat.size()<<endl;
    for(int j=0;j<Nat.size();j++){
        if(j==0){
            cout<<Nat[j].id<<" "<<j+1<<" "<<Nat[j].location_number<<" "<<Nat[j].localRank<<endl;
        }
        else{
            if(Nat[j].score==Nat[j-1].score){
                cnt++;
                cout<<Nat[j].id<<" "<<j+1-cnt<<" "<<Nat[j].location_number<<" "<<Nat[j].localRank<<endl;
            }
            else{
                cnt=0;
                cout<<Nat[j].id<<" "<<j+1<<" "<<Nat[j].location_number<<" "<<Nat[j].localRank<<endl;
            }
        }
    }
    return 0;
}
/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
*/
