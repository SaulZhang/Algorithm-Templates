#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 1e5+5;
const int M = 200+5;
const int inf = 99999999;
struct Person{
    string name;
    int age;
    int worth;
    Person(string _n,int _a,int _w){name=_n,age=_a,worth=_w;}
    bool operator < (const Person&x)const{
        if(worth!=x.worth){
            return worth>x.worth;
        }
        else if(age!=x.age){
            return age<x.age;
        }
        else{
            return name<x.name;
        }
    }
};
vector<Person> Vec[M];
set<Person> tmpS;
int n,k,a,w,m,amin,amax,Amin=inf,Amax=0;
string name;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>name>>a>>w;
        if(a>Amax)Amax=a;
        if(a<Amin)Amin=a;
        Vec[a].push_back(Person(name,a,w));
    }
    for(int i=1;i<=200;i++)
        sort(Vec[i].begin(),Vec[i].end());
    for(int l=1;l<=k;l++){
        cin>>m>>amin>>amax;
        tmpS.clear();
        int cnt=0;
        cout<<"Case #"<<l<<":"<<endl;
        if(amax<Amin||amin>Amax)
            cout<<"None"<<endl;
        else{
            vector<int>pos(200+5,0);
            for(int i=1;i<=m;i++){
                int maxEle = -1*inf;
                int maxIdx = -1;
                for(int j=amin;j<=amax;j++){
                    if(pos[j]<Vec[j].size()&&Vec[j][pos[j]].worth>maxEle){
                        maxEle = Vec[j][pos[j]].worth;
                        maxIdx = j;
                    }
                }
                if(maxIdx!=-1){
                    tmpS.insert(Vec[maxIdx][pos[maxIdx]]);
                    cnt++;
                    pos[maxIdx]++;
                }

            }
            if(cnt==0)
                cout<<"None"<<endl;
            else{
                cnt=0;
                for(auto it=tmpS.begin();it!=tmpS.end();it++){
                    cout<<it->name<<" "<<it->age<<" "<<it->worth<<endl;
                    cnt++;
                    if(cnt==m) break;
                }
            }
        }
    }
    return 0;
}
/*
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
*/
