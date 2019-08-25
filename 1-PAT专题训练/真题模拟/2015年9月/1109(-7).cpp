#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Person{
    string name;
    int h;
    bool operator<(const Person& x)const{
        if(h!=x.h)
            return h<x.h;
        else
            return name<x.name;
    }
}Vec[10000+5];
bool cmp(Person a,Person b){
        if(a.h!=b.h)
            return a.h>b.h;
        else
            return a.name<b.name;
}
int n,k,h,loc=0;
string name,ans="";
vector<string> tmp;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>name>>h;
        Vec[loc++]=Person{name,h};
    }
    if(n<=k){
        sort(Vec,Vec+loc,cmp);
        for(int j=0;j<loc;j++){
            if(j%2==0)
                tmp.push_back(Vec[j].name);
            else
                tmp.insert(tmp.begin(),Vec[j].name);
        }
        string line="";
        for(int j=0;j<tmp.size();j++){
            line+=tmp[j];
            if(j==tmp.size()-1)
                line+="\n";
            else
                line+=" ";
        }
        cout<<line;
        return 0;
    }
    sort(Vec,Vec+loc);

    for(int i=0;i<n/k;i++){
        tmp.clear();
        if(i!=n/k-1){
            sort(Vec+i*k,Vec+(i+1)*k,cmp);
            for(int j=0;j<k;j++){
                if(j%2==0)
                    tmp.push_back(Vec[i*k+j].name);
                else
                    tmp.insert(tmp.begin(),Vec[i*k+j].name);
            }
        }
        else{
            sort(Vec+i*k,Vec+loc,cmp);
            for(int j=0;j<k+n%k;j++){
                if(j%2==0)
                    tmp.push_back(Vec[i*k+j].name);
                else
                    tmp.insert(tmp.begin(),Vec[i*k+j].name);
            }
        }
        string line="";
        for(int j=0;j<tmp.size();j++){
            line+=tmp[j];
            if(j==tmp.size()-1)
                line+="\n";
            else
                line+=" ";
        }
        ans = line+ans;
    }
    cout<<ans;
    return 0;
}
/*
1 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
*/
