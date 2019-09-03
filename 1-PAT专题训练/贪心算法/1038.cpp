#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<string>Vec,tmp;
bool cmp(string a,string b){
    return a<b;
}
bool isPrefix(string a,string b){
    if(a.size()>=b.size())
        return false;
    else{
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
}
int main()
{
    cin>>n;
    Vec.resize(n);
    for(int i=0;i<n;i++)
        cin>>Vec[i];
    sort(Vec.begin(),Vec.end(),cmp);
    string ans="";
    int pos=0;
    while(pos<n){
        tmp.clear();
        tmp.push_back(Vec[pos]);
        if(pos+1<n&&isPrefix(Vec[pos],Vec[pos+1])){
            while(pos+1<n&&isPrefix(Vec[pos],Vec[pos+1]))tmp.push_back(Vec[++pos]);
            string str= "99999999";
            do{
                string tmpstr="";
                for(int i=0;i<tmp.size();i++) tmpstr+=tmp[i];
                if(tmpstr<str)str=tmpstr;
            }while(next_permutation(tmp.begin(),tmp.end()));
            ans+=str;
        }
        else{
            ans+=Vec[pos];
        }
        pos++;
    }
    int i = 0;
    while(ans[i]=='0'&&i<ans.size())i++;//去除前导0
    if(ans.substr(i,ans.size()-i).size()!=0)
        cout<<ans.substr(i,ans.size()-i)<<endl;
    else
        cout<<"0"<<endl;
    return 0;
}
