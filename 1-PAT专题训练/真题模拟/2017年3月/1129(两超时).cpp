#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 50000+5;
vector<int> Vec;
int freq[N],n,x,k;
bool cmp(int a,int b){
    if(freq[a]!=freq[b])
        return freq[a]>freq[b];
    else
        return a<b;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i!=1){
            sort(Vec.begin(),Vec.end(),cmp);
            cout<<x<<":";
            for(int j=0;j<min(k,int(Vec.size()));j++)
                cout<<" "<<Vec[j];
            cout<<endl;
        }
        freq[x]++;
        if(freq[x]==1)//首次出现
            Vec.push_back(x);
    }
    return 0;
}
/*
12 3
3 5 7 5 5 3 2 1 8 3 8 12

5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8
*/
