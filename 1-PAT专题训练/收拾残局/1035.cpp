#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
string name,password;
struct User{
    string name,password;
};
vector<User> Vec,res;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>name>>password;
        Vec.push_back(User{name,password});
    }
    for(int i=0;i<Vec.size();i++){
        bool flag=false;
        for(int j=0;j<Vec[i].password.size();j++){
            if(Vec[i].password[j]=='1'){
                Vec[i].password[j]='@';flag=true;
            }
            else if(Vec[i].password[j]=='0'){
                Vec[i].password[j]='%';flag=true;
            }
            else if(Vec[i].password[j]=='l'){
                Vec[i].password[j]='L';flag=true;
            }
            else if(Vec[i].password[j]=='O'){
                Vec[i].password[j]='o';flag=true;
            }
        }
        if(flag){
            res.push_back(User{Vec[i].name,Vec[i].password});
        }
    }
    if(res.size()==0){
        if(n==1)
            cout<<"There is "<<n<<" account and no account is modified"<<endl;
        else
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
    else{
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++)
            cout<<res[i].name<<" "<<res[i].password<<endl;
    }
    return 0;
}
/*
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
*/
