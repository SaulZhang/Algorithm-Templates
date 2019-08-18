#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char,int> M2;
string str1,str2;
int main()
{
    cin>>str1>>str2;
    for(int i=0;i<str2.size();i++){
        M2[str2[i]]++;
    }
    for(int i=0;i<str1.size();i++){
        if(M2.count(str1[i])!=0) M2[str1[i]]--;
    }
    bool flag=false;
    int cnt=0;
    for(auto it=M2.begin();it!=M2.end();it++){
        cnt+=max(it->second,0);
    }
    if(cnt==0)
        flag = true;
    if(flag)
        cout<<"Yes "<<str1.size()-str2.size()<<endl;
    else
        cout<<"No "<<cnt<<endl;

    return 0;
}
