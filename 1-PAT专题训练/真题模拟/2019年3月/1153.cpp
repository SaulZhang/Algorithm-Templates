#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 10000+5;
int n,m,score,type;
string info,term;
map<string,map<string,int>> Date_site_num;

struct Item{
    string info;
    int score;
    Item(string _info,int _score){
        info=_info;score=_score;
    }
    string getL(){
        return info.substr(0,1);
    }
    string getsite(){
        return info.substr(1,3);
    }
    string getdate(){
        return info.substr(4,6);
    }
    string getnum(){
        return info.substr(10,3);
    }
    bool operator<(const Item&x)const{
        if(score!=x.score)
            return score>x.score;
        else
            return info<x.info;
    }
};
struct Site{
    string site;
    int num;
    Site(string _site,int _num){site=_site;num=_num;}
    bool operator<(const Site&x)const{
        if(num!=x.num)
            return num<x.num;
        else
            return site>x.site;
    }
};
bool cmp1(Item it1,Item it2){
    if(it1.score!=it2.score)
        return it1.score>it2.score;
    else
        return it1.info<it2.info;
}
vector<Item>Vec_T,Vec_A,Vec_B,ans;
priority_queue<Site>Vecs;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>info>>score;
        Date_site_num[info.substr(4,6)][info.substr(1,3)]++;
        if(info[0]=='T')
            Vec_T.push_back(Item(info,score));
        else if(info[0]=='A')
            Vec_A.push_back(Item(info,score));
        else if(info[0]=='B')
            Vec_B.push_back(Item(info,score));
    }
    for(int i=1;i<=m;i++){
        cin>>type>>term;
        if(type==1){
            if(term=="T"){
                sort(Vec_T.begin(),Vec_T.end(),cmp1);
                cout<<"Case "<<i<<": "<<type<<" "<<term<<endl;
                if(Vec_T.size()!=0)
                    for(int j=0;j<Vec_T.size();j++){
                        cout<<Vec_T[j].info<<" "<<Vec_T[j].score<<endl;
                    }
                else
                    cout<<"NA"<<endl;
            }
            else if(term=="A"){
                sort(Vec_A.begin(),Vec_A.end(),cmp1);
                cout<<"Case "<<i<<": "<<type<<" "<<term<<endl;
                if(Vec_A.size()!=0)
                    for(int j=0;j<Vec_A.size();j++){
                        cout<<Vec_A[j].info<<" "<<Vec_A[j].score<<endl;
                    }
                else
                    cout<<"NA"<<endl;
            }
            else if(term=="B"){
                sort(Vec_B.begin(),Vec_B.end(),cmp1);
                cout<<"Case "<<i<<": "<<type<<" "<<term<<endl;
                if(Vec_B.size()!=0)
                    for(int j=0;j<Vec_B.size();j++){
                        cout<<Vec_B[j].info<<" "<<Vec_B[j].score<<endl;
                    }
                else
                    cout<<"NA"<<endl;
            }
        }
        else if(type==2){
            int totnum=0,totscore=0;
            for(int j=0;j<Vec_A.size();j++){
                if(Vec_A[j].getsite()==term){
                    totnum++;
                    totscore+=Vec_A[j].score;
                }
            }
            for(int j=0;j<Vec_B.size();j++){
                if(Vec_B[j].getsite()==term){
                    totnum++;
                    totscore+=Vec_B[j].score;
                }
            }
            for(int j=0;j<Vec_T.size();j++){
                if(Vec_T[j].getsite()==term){
                    totnum++;
                    totscore+=Vec_T[j].score;
                }
            }
            cout<<"Case "<<i<<": "<<type<<" "<<term<<endl;
            if(totnum!=0)
                cout<<totnum<<" "<<totscore<<endl;
            else
                cout<<"NA"<<endl;
        }
        else if(type==3){
            while(!Vecs.empty())Vecs.pop();
            cout<<"Case "<<i<<": "<<type<<" "<<term<<endl;
            if(Date_site_num[term].size()!=0){

                for(auto it=Date_site_num[term].begin();it!=Date_site_num[term].end();it++){
                    Vecs.push(Site(it->first,it->second));
                }
                while(!Vecs.empty()){
                    Site tmp = Vecs.top();
                    Vecs.pop();
                    cout<<tmp.site<<" "<<tmp.num<<endl;
                }
            }
            else{
                cout<<"NA"<<endl;
            }
        }
    }
    return 0;
}
/*
8 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
1 A
2 107
3 180908
2 999
*/
