#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
string A,B,token;
vector<int> An,Bn,res;
int main()
{
    cin>>A>>B;
    stringstream ssA(A),ssB(B);
    while(getline(ssA,token,'.')){
        An.push_back(stoi(token));
    }
    while(getline(ssB,token,'.')){
        Bn.push_back(stoi(token));
    }
    int c=0,cur=0;//10^7 17 29
    res.resize(3);
    for(int i=2;i>=0;i--){
        if(i==2){
            cur = (An[i]+Bn[i]+c)%29;
            c = (An[i]+Bn[i]+c)/29;
        }
        else if(i==1){
            cur = (An[i]+Bn[i]+c)%17;
            c = (An[i]+Bn[i]+c)/17;
        }
        else{
            cur = (An[i]+Bn[i]+c);
        }
        res[i]=cur;
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1)
            cout<<".";
    }
    cout<<endl;
    return 0;
}
