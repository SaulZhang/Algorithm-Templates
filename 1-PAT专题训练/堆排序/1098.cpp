#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100+5;
int n,x;
vector<int> Seq1,Seq2;
bool IsInsertionSort(){
    int i=1;
    while(i<=n-1){//找到第一个不满足从小到大排序的元素
        if(Seq2[i-1]<=Seq2[i]) i++;
        else break;
    }
    int idx = i;//记录查找到的元素的小标，方便进行下一步的插排
    while(i<n){
        if(Seq1[i]==Seq2[i]) i++;
        else break;
    }
    if(i==n){
        sort(Seq2.begin(),Seq2.begin()+idx+1);//将第一个非排序数插入到前面的有序数组中
        return true;
    }
    else return false;
}
bool isMax(int idx){
    for(int i=0;i<idx;i++)
        if(Seq2[i]>Seq2[idx]) return false;
    return true;
}
void maxHeap(int st,int ed){
    int parent = st;
    int son = 2*parent+1;
    while(son<=ed){
        if(son+1<=ed&&Seq2[son+1]>Seq2[son]) son++;
        if(Seq2[parent]>Seq2[son])return;
        else{
            swap(Seq2[parent],Seq2[son]);
            parent = son;
            son = 2*parent+1;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;Seq1.push_back(x);}
    for(int i=0;i<n;i++){cin>>x;Seq2.push_back(x);}
    if(IsInsertionSort()){
        cout<<"Insertion Sort"<<endl;
        for(int i=0;i<Seq2.size();i++){
            cout<<Seq2[i];
            if(i!=Seq2.size()-1) cout<<" ";
        }
    }
    else{
        cout<<"Heap Sort"<<endl;
        int idx=n-1;
        while(isMax(idx))idx--;
        swap(Seq2[0],Seq2[idx]);
        maxHeap(0,idx-1);
        for(int i=0;i<n;i++){
            cout<<Seq2[i];
            if(i!=Seq2.size()-1) cout<<" ";
        }
    }
    return 0;
}
