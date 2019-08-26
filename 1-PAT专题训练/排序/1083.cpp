#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Stu{
    string name,sno;
    int score;
    bool operator<(const Stu&x)const{
        return score>x.score;
    }
};
int n,score,grade1,grade2,cnt=0;
vector<Stu>Vec;
string name,sno;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>sno>>score;
        Vec.push_back(Stu{name,sno,score});
    }
    sort(Vec.begin(),Vec.end());
    cin>>grade1>>grade2;
    for(int i=0;i<Vec.size();i++){
        if(Vec[i].score>=grade1&&Vec[i].score<=grade2){
            cnt++;
            cout<<Vec[i].name<<" "<<Vec[i].sno<<endl;
        }
    }
    if(cnt==0)
        cout<<"NONE"<<endl;
    return 0;
}
