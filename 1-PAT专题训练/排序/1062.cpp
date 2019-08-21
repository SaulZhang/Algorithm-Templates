#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Per{
    string id;
    int vg,tg;
    Per(string _id,int _vg,int _tg){id=_id,vg=_vg,tg=_tg;}
};
int n,l,h,vg,tg;
string id;
vector<Per> Vec1,Vec2,Vec3,Vec4,Ans;
bool cmp(Per a,Per b){
    if(a.tg+a.vg!=b.tg+b.vg)
        return a.tg+a.vg>b.tg+b.vg;
    else if(a.vg!=b.vg)
        return a.vg>b.vg;
    else
        return a.id<b.id;
}
int main()
{
    cin>>n>>l>>h;
    for(int i=1;i<=n;i++){
        cin>>id>>vg>>tg;
        if(vg>=l&&tg>=l){
            if(vg>=h&&tg>=h)Vec1.push_back(Per(id,vg,tg));
            else if(tg<h&&vg>=h)Vec2.push_back(Per(id,vg,tg));
            else if(tg<h&&vg<h&&vg>=tg)Vec3.push_back(Per(id,vg,tg));
            else Vec4.push_back(Per(id,vg,tg));
        }
    }
    sort(Vec1.begin(),Vec1.end(),cmp);sort(Vec2.begin(),Vec2.end(),cmp);
    sort(Vec3.begin(),Vec3.end(),cmp);sort(Vec4.begin(),Vec4.end(),cmp);
    for(int i=0;i<Vec1.size();i++)
        Ans.push_back(Vec1[i]);
    for(int i=0;i<Vec2.size();i++)
        Ans.push_back(Vec2[i]);
    for(int i=0;i<Vec3.size();i++)
        Ans.push_back(Vec3[i]);
    for(int i=0;i<Vec4.size();i++)
        Ans.push_back(Vec4[i]);
    cout<<Ans.size()<<endl;
    for(int i=0;i<Ans.size();i++)
        cout<<Ans[i].id<<" "<<Ans[i].vg<<" "<<Ans[i].tg<<endl;
    return 0;
}
