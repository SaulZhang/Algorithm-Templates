#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100000+5;
string id,school;
unordered_map<string,vector<double>> Map;
int n,loc=0;
double Abs(double x){return x<0?-1*x:x;}
double score,tmpscore;
struct Ins{
    string school;
    int tws;
    int ns;
    Ins(string _s,int _t,int _ns){
        school = _s,tws = _t,ns = _ns;
    }
    Ins(){};
    bool operator<(const Ins& x)const{
        if(tws!=x.tws){
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
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>id>>score>>school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if(id[0]=='B'){
            tmpscore = score/1.5;
        }
        else if(id[0]=='A'){
            tmpscore = 1.0*score;
        }
        else if(id[0]=='T'){
            tmpscore = 1.5*score;
        }
        if(Map.count(school)==0){
            Map[school].push_back(0);
            Map[school].push_back(0);
            Map[school][0] += tmpscore;
            Map[school][1] += 1;
        }
        else{
            Map[school][0] += tmpscore;
            Map[school][1] += 1;
        }
    }
    for(auto it=Map.begin();it!=Map.end();it++){
        buf[loc]=Ins(it->first,int(it->second[0]),int(it->second[1]));
        loc++;
    }
    sort(buf,buf+loc);
    cout<<Map.size()<<endl;
    int cnt=0;
    for(int i=0;i<loc;i++){//这个排名的方法有漏洞，这能两个人同时并列啊
        if(i==0){
            cout<<i+1<<" "<<buf[i].school<<" "<<buf[i].tws<<" "<<buf[i].ns<<endl;
        }
        else{
            if(buf[i].tws==buf[i-1].tws){
                cnt++;
                cout<<i+1-cnt<<" "<<buf[i].school<<" "<<buf[i].tws<<" "<<buf[i].ns<<endl;
            }
            else{
                cout<<i+1<<" "<<buf[i].school<<" "<<buf[i].tws<<" "<<buf[i].ns<<endl;
                cnt=0;
            }

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
