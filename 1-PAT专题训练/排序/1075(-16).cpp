#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N = 1e4+5;
const int K = 5+5;
int n,k,m,p[K],usid,pid,score_ab;
map<int,vector<int>> Ma;
map<int,vector<int>> solve;

int getSolveNum(int usid){
    int ans=0;
    for(int i=1;i<=k;i++)
        if(solve[usid][i]==1)
            ans++;
    return ans;
}

struct Stu_sco{
    int usid;
    int totScore;
    bool operator<(const Stu_sco& x)const{
        if(totScore!=x.totScore)
            return totScore>x.totScore;
        else if(getSolveNum(usid)!=getSolveNum(x.usid))
            return getSolveNum(usid)>getSolveNum(x.usid);
        else
            return usid<x.usid;
    }
};
vector<Stu_sco> Vec;

int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=k;i++)
        cin>>p[i];
    for(int i=1;i<=m;i++){
        cin>>usid>>pid>>score_ab;
        if(Ma.count(usid)==0&&score_ab!=-1){
            Ma[usid] = vector<int>(k+1,-2);
            solve[usid]= vector<int>(k+1,0);
        }
        if(Ma.count(usid)!=0) {
            Ma[usid][pid] = max(Ma[usid][pid],score_ab);
            if(score_ab==p[pid])
                solve[usid][pid] = 1;
        }
    }
    for(auto it=Ma.begin();it!=Ma.end();it++){
        //calcuiate the total score.
        int tmpscore=0;
        for(int i=1;i<=k;i++){
            if(it->second[i]>0)
                tmpscore += it->second[i];
        }
        Vec.push_back(Stu_sco{it->first,tmpscore});
    }
    sort(Vec.begin(),Vec.end());
    int cnt=0;
    for(int i=0;i<Vec.size();i++){
        if(i==0){
            cout<<i+1<<" ";
            printf("%05d",Vec[i].usid);
            cout<<" "<<Vec[i].totScore;
            for(int j=1;j<=k;j++){
                    if(Ma[Vec[i].usid][j]==-2)
                        cout<<" -";
                    else if(Ma[Vec[i].usid][j]==-1)
                        cout<<" 0";
                    else
                        cout<<" "<<Ma[Vec[i].usid][j];
            }
            cout<<endl;
        }
        else{
            if(Vec[i].totScore==Vec[i-1].totScore){
                cnt++;
                cout<<i+1<<" ";
                printf("%05d",Vec[i].usid);
                cout<<" "<<Vec[i].totScore;
                for(int j=1;j<=k;j++){
                    if(Ma[Vec[i].usid][j]==-2)
                        cout<<" -";
                    else if(Ma[Vec[i].usid][j]==-1)
                        cout<<" 0";
                    else
                        cout<<" "<<Ma[Vec[i].usid][j];
                }
                cout<<endl;
            }
            else{
                cnt=0;
                cout<<i+1<<" ";
                printf("%05d",Vec[i].usid);
                cout<<" "<<Vec[i].totScore;
                for(int j=1;j<=k;j++){
                    if(Ma[Vec[i].usid][j]==-2)
                        cout<<" -";
                    else if(Ma[Vec[i].usid][j]==-1)
                        cout<<" 0";
                    else
                        cout<<" "<<Ma[Vec[i].usid][j];
                }
                cout<<endl;
            }
        }


    }
    return 0;
}
