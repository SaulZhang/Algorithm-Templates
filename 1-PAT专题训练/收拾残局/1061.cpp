#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string Day[8]={"","MON","TUE","WED","THU","FRI","SAT","SUN"};
string str1,str2,str3,str4;
string solve(){
    string ans="";
    bool f1=false;
    for(int i=0;i<str1.size();i++){
        if(!f1&&str1[i]>='A'&&str1[i]<='G'){
            if(str1[i]==str2[i]){
                ans += (Day[int(str1[i]-'A'+1)]+" ");
                f1=true;
                continue;
            }
        }
        if(f1&&(str1[i]>='A'&&str1[i]<='N'||isdigit(str1[i]))){
            if(str1[i]==str2[i]){
                if(isupper(str1[i])){
                    ans += to_string(str1[i]-'A'+10);
                }
                else{
                    ans += '0'+to_string(str1[i]-'0');
                }
                ans += ":";
                break;
            }
        }
    }
    for(int i=0;i<min(str3.size(),str4.size());i++){
        if(isalpha(str3[i])&&str3[i]==str4[i]){
            if(i<10)
                ans+='0'+to_string(i);
            else
                ans+=to_string(i);
        }
    }
    return ans;
}
int main()
{
    cin>>str1>>str2>>str3>>str4;
    cout<<solve();
    return 0;
}
