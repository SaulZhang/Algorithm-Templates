#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100+5;
int n,x;
vector<int> Seq1,Seq2;
bool IsInsertionSort(){
    int i=1;
    while(i<=n-1){
        if(Seq2[i-1]<=Seq2[i])
            i++;
        else
            break;
    }
    int idx = i;
    while(i<n){
        if(Seq1[i]==Seq2[i])
            i++;
        else
            break;
    }
    if(i==n){
        sort(Seq2.begin(),Seq2.begin()+idx+1+1);
        return true;
    }
    else
        return false;
}
bool isMax(int idx){
    for(int i=0;i<idx;i++)
        if(Seq2[i]>Seq2[idx])
            return false;
    return true;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;Seq1.push_back(x);
    }
    for(int i=0;i<n;i++){
        cin>>x;Seq2.push_back(x);
    }
    if(IsInsertionSort()){
        cout<<"Insertion Sort"<<endl;
        for(int i=0;i<Seq2.size();i++){
            cout<<Seq2[i];
            if(i!=Seq2.size()-1)
                cout<<" ";
            else
                cout<<endl;
        }
    }
    else{
        int idx=n-1;
        while(isMax(idx))
            idx--;
        swap(Seq2[0],Seq2[idx]);
        for(int i=0;i<=int(idx/2)-1;i++){
            int left = 2*i+1;
            int right = 2*i+2;
            if(left<idx&&right<idx&&Seq2[i]<Seq2[left]&&Seq2[i]<Seq2[right]&&Seq2[right]>Seq2[left])
                swap(Seq2[i],Seq2[right]);
            else if(left<idx&&right<idx&&Seq2[i]<Seq2[left]&&Seq2[i]<Seq2[right]&&Seq2[right]<Seq2[left])
                swap(Seq2[i],Seq2[left]);
            else if(left<idx&&Seq2[i]<Seq2[left])
                swap(Seq2[i],Seq2[left]);
            else if(right<idx&&Seq2[i]<Seq2[right])
                swap(Seq2[i],Seq2[right]);
        }
        cout<<"Heap Sort"<<endl;
        for(int i=0;i<n;i++){
            cout<<Seq2[i];
            if(i!=n-1)
                cout<<" ";
        }
    }
    return 0;
}
/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
*/

