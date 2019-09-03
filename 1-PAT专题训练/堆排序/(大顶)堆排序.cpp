#include <iostream>
using namespace std;
const int N = 30;
int A[N] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
void maxHeap(int st,int ed){
    int parent = st;
    int son = 2*parent+1;
    while(son<=ed){
        if(son+1<=ed&&A[son]<A[son+1]) son++;//选孩子代表
        if(A[parent]>A[son]) return;//调整完毕
        else{
            swap(A[son],A[parent]);//交换父子逆序对
            parent = son;
            son = 2*parent+1;
        }
    }
}
void HeapSort(int len){
    for(int i=len/2-1;i>=0;i--)//从最后一个非叶子结点开始自下往上进行调整
        maxHeap(i,len-1);
    for(int i=len-1;i>=0;i--){//交换头部和尾部的元素，然后继续调整堆的结构
        swap(A[0],A[i]);//(可以看成将堆顶的元素取出，然后继续调整堆的结构)
        maxHeap(0,i-1);
    }
}
int main()
{
    HeapSort(N);
    for(int i=0;i<N;i++){
        cout<<A[i];
        if(i!=N-1) cout<<" ";
    }
    return 0;
}
