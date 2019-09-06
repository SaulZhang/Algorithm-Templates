#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int n;
string str1,str2;
string solve(string str,int n){
    vector<char>tmp;
    int flag=false;//首位是否非零，用于消除前导0
    int flagdot=false;//是否遇到小数点
    int cnt=0;//小数点前有几个有效数字
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])&&str[i]!='0')flag=true;
        if(isdigit(str[i])&&flag){
            tmp.push_back(str[i]);
            if(!flagdot)cnt++;
        }
        if(str[i]=='.')flagdot=true;
    }
    string ans="0.";
    for(int i=0;i<n;i++){
        if(i<tmp.size())
            ans+=tmp[i];
        else
            ans+='0';
    }
    ans+=("*10^"+to_string(cnt));
    return ans;
}
int main()
{
    cin>>n>>str1>>str2;
    str1 = solve(str1,n);
    str2 = solve(str2,n);
    if(str1==str2)
        cout<<"YES "<<str1<<endl;
    else
        cout<<"NO "<<str1<<" "<<str2<<endl;
    return 0;
}
