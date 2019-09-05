#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+5;
struct Pair{
    int i,j,pri;
};
int A[N],n,m;
vector<Pair>V_eq,V_max;
int main()
{
    scanf("%d%d",&n,&m);
    A[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        A[i]+=A[i-1];
    }
    int i=1,j=1;
    while(i<=n&&j<=n){
        if(A[j]-A[i-1]==m){
            V_eq.push_back(Pair{i,j,m});
            V_max.clear();
            i++;j++;
        }
        else if(A[j]-A[i-1]>m){
            if(V_eq.size()==0){
                if(V_max.size()==0){
                    V_max.push_back(Pair{i,j,A[j]-A[i-1]});
                }
                else if(A[j]-A[i-1]<V_max[V_max.size()-1].pri){
                    V_max.clear();
                    V_max.push_back(Pair{i,j,A[j]-A[i-1]});
                }
                else if(A[j]-A[i-1]==V_max[V_max.size()-1].pri){
                    V_max.push_back(Pair{i,j,A[j]-A[i-1]});
                }
            }
            i++;
        }
        else{
            j++;
        }
    }
    if(V_eq.size()!=0){
        for(int i=0;i<V_eq.size();i++){
            printf("%d-%d\n",V_eq[i].i,V_eq[i].j);
        }
    }
    else{
        for(int i=0;i<V_max.size();i++){
            printf("%d-%d\n",V_max[i].i,V_max[i].j);
        }
    }
    return 0;
}
