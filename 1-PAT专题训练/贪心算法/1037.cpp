#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int nc,np;
int num_pos_c=0,num_pos_p=0;
long long ans=0;
vector<long long> vc,vp;
int main()
{
    cin>>nc;vc.resize(nc);
    for(int i=0;i<nc;i++){
        cin>>vc[i];
        if(vc[i]>0) num_pos_c++;
    }
    cin>>np;vp.resize(np);
    for(int i=0;i<np;i++){
        cin>>vp[i];
        if(vp[i]>0) num_pos_p++;
    }
    sort(vc.begin(),vc.end(),greater<int>());
    sort(vp.begin(),vp.end(),greater<int>());
    for(int i=0;i<min(num_pos_c,num_pos_p);i++)
        ans+=vc[i]*vp[i];
    for(int i=nc-1;i>nc-1-min(nc-num_pos_c,np-num_pos_p);i--)
        ans+=vc[i]*vp[np-1-((nc-1)-i)];
    cout<<ans<<endl;
    return 0;
}
