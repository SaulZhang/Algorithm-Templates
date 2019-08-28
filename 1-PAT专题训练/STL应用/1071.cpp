#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
string str,tmp;
map<string,int>Cnt;
bool isTarget(char c){
    if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')))
        return false;
    return true;
}
int main()
{
    getline(cin,str);
    int len = str.size();
    for(int i=0;i<len;i++){
        if(isTarget(str[i]))
            str[i] = tolower(str[i]);
        else
            str[i] = ' ';
    }
    stringstream ss(str);
    while(ss>>tmp) Cnt[tmp]++;//按空格进行分割
    int maxNum=0;
    string ans;
    for(auto it=Cnt.begin();it!=Cnt.end();it++){
        if(it->second>maxNum){
            maxNum=it->second;ans = it->first;
        }
        else if(it->second==maxNum&&it->first<ans){
            ans = it->first;
        }
    }
    cout<<ans<<" "<<maxNum<<endl;
    return 0;
}
