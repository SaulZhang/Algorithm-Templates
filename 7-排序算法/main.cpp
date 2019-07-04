/*
description:This is a small exercise to implement all kinds of sort algorithms.
author:saulzhang
data:2019-7-4 17:07
place:NWPU
*/
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int A[10] = {2,5,10,7,3,8,6,4,9,1};


/**插入排序*/

//直接插入排序
/*每次选取一个元素，插入其前面的有序列的指定位置中，并保持其有序性*/
void insertSort(int n){

    for(int i=0;i<n;i++){
        int tmp = A[i];
        int cnt=1;
        int mark=0;
        while(i-cnt>=0&&A[i-cnt]>tmp){
            A[i-cnt+1] = A[i-cnt];
            cnt++;
            mark=1;
        }
        if(mark==1)
            A[i-cnt+1] = tmp;;
    }

}

//折半插入排序
/*在选择插入位置的时候采用二分的思想，在确定了插入的位置之后在把元素统一往右移动一格*/
void selfInsertSort(int n){

    for(int i=0;i<n;i++){
        int tmp = A[i];
        int cnt=1;

        int pos = upper_bound(A,A+i-1,A[i])-A;//采用二分查找，找到当前元素应该插入的位置

        //当找到的下标刚好位于数组的尾部的时候需要进行特殊判断，
        //此时可能是没找到也有可能是刚好在最后一个元素找到了
        if(!(pos==i-1&&A[pos]<=A[i])){
            for(int k=i-1;k>=0&&k>=pos;k--){
                A[k+1] = A[k];
            }
            A[pos] = tmp;
        }

    }

}

//希尔排序
/*希尔排序的基本思想是先将偏序表分割为形如L[i,i+d,i+2d,...,i+kd]的特殊子表，
分别进行直接插入排序，当整个表已经基本有序的时候，再对全体记录进行一次直接插入
排序*/

void shellSort(int n){

    for(int gap=n/2;gap>=1;gap/=2){
        for(int i=0;i<n;i++){
            int tmp = A[i];
            int cnt=1;
            int mark=0;
            while(i-cnt*gap>=0&&A[i-cnt*gap]>tmp){
                A[i-cnt*gap+gap] = A[i-cnt*gap];
                cnt++;
                mark=1;
            }
            if(mark==1)
                A[i-cnt*gap+gap] = tmp;
        }
        for(int i=0;i<10;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
}


/**交换排序*/

//冒泡排序
void bubbleSort(int n){

    for(int i=0;i<n;i++){
        bool isChange = false;//记录本趟过程中序列是否发生了变化
        for(int j=1;j<n-i;j++){
            if(A[j-1]>A[j])
                swap(A[j-1],A[j]),isChange = true;
        }
        if(!isChange)
            return ;
    }

}

//快速排序
void QuickSort(int l,int r){

    if(l<=r){
        int p = l;//partition benchmark
        int t = r;//another side benchmark

        while(p!=t){//扫描还需要继续的条件
            // 扫描 <-----
            while(A[p]<A[t]&&t>=p)t--;
            if(t>p)swap(A[p],A[t]),swap(t,p),t++;
            // 扫描 ----->
            while(A[t]<A[p]&&t<=p)t++;
            if(t<p)swap(A[p],A[t]),swap(t,p),t--;
        }
        QuickSort(l,p-1);
        QuickSort(p+1,r);
    }

}


/**选择排序*/

//简单选择排序
void selectSort(int n){

    for(int i=0;i<n-1;i++){
        int Min=i;
        for(int j=i;j<n;j++){
            if(A[j]<A[Min]){
                Min = j;
            }
        }
        if(Min!=i)
        swap(A[i],A[Min]);
    }
}

//堆排序
/*将数据的存储看成一颗完全二叉树(堆)，有小根堆和大根堆这两种类型*/

/*堆排序的基本思想是：将待排序序列构造成一个大顶堆，此时，整个序列
的最大值就是堆顶的根节点。将其与末尾元素进行交换，此时末尾就为最大值。
然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。
如此反复执行，便能得到一个有序序列了*/

void heapSort(int n){

    for(int k=n-1;k>=0;k--){//每一次循环的过程即为一次堆的构建，每次都将当前中最大的元素浮出到堆顶
        for(int i=k/2;i>=0;i--){
            if(2*i+1<=k&&A[i]<A[2*i+1]){
                swap(A[i],A[2*i+1]);
            }
            if(2*i+2<=k&&A[i]<A[2*i+2])
                swap(A[i],A[2*i+2]);
        }
        swap(A[0],A[k]);//将最大的结点直接插到数组尾部，在后续的更新过程中将不在更新数组的尾部
    }

}


/**归并排序*/

int temp[10];//中间数组

void mergeSort(int l,int r){

    if(l<r){

        int mid = (l+r)/2;
        mergeSort(l,mid);
        mergeSort(mid+1,r);
        //Merge two subArray.
        int pos =l;
        int idx1 = l;
        int idx2 = mid+1;

        for(int i=l;i<=r;i++){
            if(idx2>r)
                temp[i] = A[idx1++];
            else if(idx1>mid)
                temp[i] = A[idx2++];
            else if(A[idx1]>A[idx2])
                temp[i] = A[idx2++];
            else if(A[idx2]>A[idx1])
                temp[i] = A[idx1++];
        }
        //update the source array.
        for(int i=l;i<=r;i++)
            A[i] = temp[i];

    }
}

/**基数排序*/
/*采用每一个数的从高位到低位的信息进行排序*/

/**桶排序*/
/*将数据按范围分为几组，每一组都属于一个范围，可以将每一组看成一个桶，然后在桶内进行排序*/

/**计数排序*/
/*当数据的范围已知且不是特别大的时候，可以采用一个数组来统计每一个元素出现的次数，
其中数组的下标就是当前元素的值*/

void countSort(int n){
    int counter[101];//假设所有数均小于100
    memset(counter,0,sizeof(counter));
    for(int i=0;i<n;i++){
        if(A[i]<100)
        counter[A[i]]++;
    }
    int cnt=0;
    for(int i=0;i<100;i++){
        while(counter[i]!=0){
            A[cnt++] = i;
            counter[i]--;
        }
    }
}

/**睡眠排序*/
/*将每一个数字作为一个进程的睡眠时长，然后根据进程苏醒的先后顺序来进行排序*/

/**猴排序*/
/*将整个序列随机打乱，判断是否有序，如果无需，再重新打乱-。-呵呵，猴一下很开心*/


int main()
{
//  insertSort(10);
    mergeSort(0,9);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    cout<<endl;

}

