#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;
map<string,string> Ma;
map<string,bool> Check;
bool IsPrime(int x){
    int up = int(sqrt(x))+1;
    for(int i=2;i<up;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
int main()
{
    int n,k;
    string str;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        if(i==1)
            Ma[str]="Mystery Award";
        else if(IsPrime(i))
            Ma[str]="Minion";
        else
            Ma[str]="Chocolate";
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>str;
        if(Ma.count(str)==0){
            cout<<str<<": Are you kidding?"<<endl;
        }
        else{
            if(!Check[str]){
                cout<<str<<": "<<Ma[str]<<endl;
                Check[str]=true;
            }
            else{
                cout<<str<<": Checked"<<endl;
            }

        }
    }
    return 0;
}

