#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100000+5;
string id,school;
unordered_map<string,vector<double>> Map;
int n,loc=0,score;
double Abs(double x){return x<0?-1*x:x;}
struct Ins{
    string school;
    double tws;
    int ns;
    Ins(string _s,double _t,int _ns){
        school = _s,tws = _t,ns = _ns;
    }
    Ins(){};
    bool operator<(const Ins& x)const{
        if(Abs(tws-x.tws)>1e-7){
            return tws>x.tws;
        }
        else if(ns!=x.ns){
            return ns<x.ns;
        }
        else{
            return school<x.school;
        }
    }

}buf[N];
double levelIndex(string str){
    if(str[0]=='B'){
        return 1.0/1.5;
    }
    else if(str[0]=='A'){
        return 1.0;
    }
    else{
        return 1.5;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>id>>score>>school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if(Map.count(school)==0){
            Map[school].push_back(0);
            Map[school].push_back(0);
            Map[school][0] += levelIndex(id)*1.0*score;
            Map[school][1] += 1;
        }
        else{
            Map[school][0] += levelIndex(id)*1.0*score;
            Map[school][1] += 1;
        }
    }
    for(auto it=Map.begin();it!=Map.end();it++){
        buf[loc]=Ins(it->first,int(it->second[0]),int(it->second[1]));
        loc++;
    }
    sort(buf,buf+loc);
    cout<<Map.size()<<endl;
    for(int i=0;i<loc;i++){
        if(i==0){
            cout<<i+1<<" "<<buf[i].school<<" "<<buf[i].tws<<" "<<buf[i].ns<<endl;
        }
        else{
            if(Abs(buf[i].tws-buf[i-1].tws)<1e-7){
                cout<<i<<" "<<buf[i].school<<" "<<buf[i].tws<<" "<<buf[i].ns<<endl;
            }
            else
                cout<<i+1<<" "<<buf[i].school<<" "<<buf[i].tws<<" "<<buf[i].ns<<endl;
        }
    }
    return 0;
}
/*
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
*/
