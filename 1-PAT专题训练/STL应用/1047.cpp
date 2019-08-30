#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2500+5;
const int M = 4*1e+5;
vector<int> Vec[N];
int n,m,k,cId;
char Name[M][5];

bool cmp(int a,int b){return strcmp(Name[a],Name[b])<0;}
int main()
{
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++){
        scanf("%s %d",Name[i],&k);
        for(int j=1;j<=k;j++){
            cin>>cId;
            Vec[cId].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d %d\n",i,Vec[i].size());
        sort(Vec[i].begin(),Vec[i].end(),cmp);
        for(int j=0;j<Vec[i].size();j++)
            printf("%s\n",Name[Vec[i][j]]);
    }
    return 0;
}
