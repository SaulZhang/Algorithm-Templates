#include <iostream>
#include <vector>
using namespace std;
const int N = 1000+5;
int m,n,A[N];
vector<int> Vec[N],pre;
bool isMaxHeap(int n){
    bool res=true;
    for(int i=1;i<=n/2;i++){
        if(A[2*i]>A[i]||(2*i+1<=n&&A[2*i+1]>A[i])){
            res = false;
            break;
        }
    }
    return res;
}

bool isMinHeap(int n){
    bool res=true;
    for(int i=1;i<=n/2;i++){
        if(A[2*i]<A[i]||(2*i+1<=n&&A[2*i+1]<A[i])){
            res = false;
            break;
        }
    }
    return res;
}

void preOrder(int x){
    if(2*x<=n)
        preOrder(2*x);
    if(2*x+1<=n)
        preOrder(2*x+1);
    pre.push_back(A[x]);
}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>A[j];
        }
        for(int i=1;i<=n;i++){
            Vec[i].clear();
        }
        for(int j=2;j<=n;j++){
            Vec[j/2].push_back(j);
        }
        pre.clear();
        pre.push_back(A[1]);
        bool isMax = isMaxHeap(n);
        bool isMin = isMinHeap(n);
        preOrder(1);
        if(isMax){
            cout<<"Max Heap"<<endl;
            for(int j=1;j<pre.size();j++){
                cout<<pre[j];
                if(j!=pre.size()-1)
                    cout<<" ";
                else
                    cout<<endl;
            }
        }
        else if(isMin){
            cout<<"Min Heap"<<endl;
            for(int j=1;j<pre.size();j++){
                cout<<pre[j];
                if(j!=pre.size()-1)
                    cout<<" ";
                else
                    cout<<endl;
            }
        }
        else{
            cout<<"Not Heap"<<endl;
            for(int j=1;j<pre.size();j++){
                cout<<pre[j];
                if(j!=pre.size()-1)
                    cout<<" ";
                else
                    cout<<endl;
            }
        }
    }
    return 0;
}
/*
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56
*/
