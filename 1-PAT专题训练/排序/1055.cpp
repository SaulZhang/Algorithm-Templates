#include <iostream>
#include <string>
#include <set>
using namespace std;
const int N = 1e5+5;
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
set<Person> S;
int n,k,a,w,m,amin,amax,Amin=99999999,Amax=0;
string name;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>name>>a>>w;
        if(a>Amax)Amax=a;
        if(a<Amin)Amin=a;
        S.insert(Person(name,a,w));
    }
    for(int i=1;i<=k;i++){
        cin>>m>>amin>>amax;
        int cnt=0;
        cout<<"Case #"<<i<<":"<<endl;
        if(amax<Amin||amin>Amax)
            cout<<"None"<<endl;
        else{
            for(auto it=S.begin();it!=S.end();it++){
                if(it->age>=amin&&it->age<=amax){
                    cout<<it->name<<" "<<it->age<<" "<<it->worth<<endl;
                    cnt++;
                }
                if(cnt==m)
                    break;
            }
            if(cnt==0)
                cout<<"None"<<endl;
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
