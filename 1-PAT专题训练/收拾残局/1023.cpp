#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char,int> Cnt1,Cnt2;

string MakeDouble(string str){
    string ans="";
    int len = str.size();
    int c=0,cur;
    for(int i=len-1;i>=0;i--){
        cur = ((str[i]-'0')+(str[i]-'0')+c)%10;
        c = ((str[i]-'0')+(str[i]-'0')+c)/10;
        ans = to_string(cur) + ans;
    }
    if(c!=0)
        ans = to_string(c) + ans;
    return ans;
}
bool check(string str1,string str2){
    if(str1.size()!=str2.size())
        return false;
    else{
        for(int i=0;i<str1.size();i++){
            Cnt1[str1[i]]++;
            Cnt2[str2[i]]++;
        }
    }
    for(auto it=Cnt1.begin();it!=Cnt1.end();it++){
        if(Cnt2[it->first]!=it->second)
            return false;
    }
    return true;
}

int main()
{
    string str,res;
    cin>>str;
    res = MakeDouble(str);
    if(check(str,res)){
        cout<<"Yes"<<endl<<res;
    }
    else
        cout<<"No"<<endl<<res;
    return 0;
}
/*
1234567899
*/
