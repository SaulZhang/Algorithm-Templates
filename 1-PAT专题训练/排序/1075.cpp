#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Stu{
    int id,totScore,rank;
    vector<int> Sco;
    int solve=0;
    bool isShow=false;
    bool operator<(const Stu&x)const{
        if(totScore!=x.totScore)
            return totScore>x.totScore;
        else if(solve!=x.solve)
            return solve>x.solve;
        else
            return id<x.id;
    }
};
int n,k,m,usid,pid,score;
vector<Stu> Vec;
vector<int> pScore;
int main()
{
    scanf("%d %d %d",&n,&k,&m);
    Vec.resize(n+1);
    for(int i=1;i<=n;i++) Vec[i].Sco.resize(k+1,-2);
    pScore.resize(k+1);
    for(int i=1;i<=k;i++) scanf("%d",&pScore[i]);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&usid,&pid,&score);
        Vec[usid].id = usid;
        Vec[usid].Sco[pid]=max(Vec[usid].Sco[pid],score);
        if(score>=0) Vec[usid].isShow=true;
    }
    for(int i=1;i<=n;i++){
        int tmptot=0;
        for(int j=1;j<=k;j++){
            if(Vec[i].Sco[j]>0) tmptot+=Vec[i].Sco[j];
            if(Vec[i].Sco[j]==pScore[j]) Vec[i].solve++;
        }
        if(tmptot!=0) Vec[i].totScore=tmptot;
    }
    sort(Vec.begin()+1,Vec.end());
    for(int i=1;i<=n;i++){
        Vec[i].rank = i;
        if(i!=1&&Vec[i].totScore==Vec[i-1].totScore)
            Vec[i].rank=Vec[i-1].rank;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(Vec[i].isShow){
            printf("%d %05d %d",Vec[i].rank,Vec[i].id,Vec[i].totScore);
            for(int j=1;j<=k;j++){
                if(Vec[i].Sco[j]==-2)
                    printf(" -");
                else if(Vec[i].Sco[j]==-1)
                    printf(" 0");
                else
                    printf(" %d",Vec[i].Sco[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
