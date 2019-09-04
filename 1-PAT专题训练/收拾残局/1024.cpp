#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string Add(string str1,string str2){
    string ans="";
    int len = str1.size();
    int c=0,cur;
    for(int i=len-1;i>=0;i--){
        cur = ((str1[i]-'0')+(str2[i]-'0')+c)%10;
        c = ((str1[i]-'0')+(str2[i]-'0')+c)/10;
        ans = to_string(cur) + ans;
    }
    if(c!=0)ans = to_string(c) + ans;
    return ans;
}
int main()
{
    string str,strres;
    int k,cnt=0;
    cin>>str>>k;
    while(cnt<k){
        strres = str;
        reverse(strres.begin(),strres.end());
        if(str==strres){
            cout<<str<<endl<<cnt<<endl;break;
        }
        else
            str = Add(str,strres);
        cnt++;
        if(cnt==k) cout<<str<<endl<<cnt<<endl;
    }
    return 0;
}
