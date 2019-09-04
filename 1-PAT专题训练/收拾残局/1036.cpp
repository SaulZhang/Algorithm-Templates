#include <iostream>
#include <string>
using namespace std;
string LowMaleName = "",HighFemaleName="",mid,fid;
int Low=101,High = -1;
string name,gender,Id;
int n,grade;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>name>>gender>>Id>>grade;
        if(gender=="F"){
            if(grade>High){
                High=grade;
                HighFemaleName=name;
                fid = Id;
            }
        }
        else{
            if(grade<Low){
                Low=grade;
                LowMaleName=name;
                mid = Id;
            }
        }
    }
    if(HighFemaleName!=""){
        cout<<HighFemaleName<<" "<<fid<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
    if(LowMaleName!=""){
        cout<<LowMaleName<<" "<<mid<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
    if(LowMaleName==""||HighFemaleName=="")
        cout<<"NA"<<endl;
    else
        cout<<High-Low<<endl;
    return 0;
}
/*
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
*/
