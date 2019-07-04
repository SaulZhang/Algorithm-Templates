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


/**��������*/

//ֱ�Ӳ�������
/*ÿ��ѡȡһ��Ԫ�أ�������ǰ��������е�ָ��λ���У���������������*/
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

//�۰��������
/*��ѡ�����λ�õ�ʱ����ö��ֵ�˼�룬��ȷ���˲����λ��֮���ڰ�Ԫ��ͳһ�����ƶ�һ��*/
void selfInsertSort(int n){

    for(int i=0;i<n;i++){
        int tmp = A[i];
        int cnt=1;

        int pos = upper_bound(A,A+i-1,A[i])-A;//���ö��ֲ��ң��ҵ���ǰԪ��Ӧ�ò����λ��

        //���ҵ����±�պ�λ�������β����ʱ����Ҫ���������жϣ�
        //��ʱ������û�ҵ�Ҳ�п����Ǹպ������һ��Ԫ���ҵ���
        if(!(pos==i-1&&A[pos]<=A[i])){
            for(int k=i-1;k>=0&&k>=pos;k--){
                A[k+1] = A[k];
            }
            A[pos] = tmp;
        }

    }

}

//ϣ������
/*ϣ������Ļ���˼�����Ƚ�ƫ���ָ�Ϊ����L[i,i+d,i+2d,...,i+kd]�������ӱ�
�ֱ����ֱ�Ӳ������򣬵��������Ѿ����������ʱ���ٶ�ȫ���¼����һ��ֱ�Ӳ���
����*/

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


/**��������*/

//ð������
void bubbleSort(int n){

    for(int i=0;i<n;i++){
        bool isChange = false;//��¼���˹����������Ƿ����˱仯
        for(int j=1;j<n-i;j++){
            if(A[j-1]>A[j])
                swap(A[j-1],A[j]),isChange = true;
        }
        if(!isChange)
            return ;
    }

}

//��������
void QuickSort(int l,int r){

    if(l<=r){
        int p = l;//partition benchmark
        int t = r;//another side benchmark

        while(p!=t){//ɨ�軹��Ҫ����������
            // ɨ�� <-----
            while(A[p]<A[t]&&t>=p)t--;
            if(t>p)swap(A[p],A[t]),swap(t,p),t++;
            // ɨ�� ----->
            while(A[t]<A[p]&&t<=p)t++;
            if(t<p)swap(A[p],A[t]),swap(t,p),t--;
        }
        QuickSort(l,p-1);
        QuickSort(p+1,r);
    }

}


/**ѡ������*/

//��ѡ������
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

//������
/*�����ݵĴ洢����һ����ȫ������(��)����С���Ѻʹ��������������*/

/*������Ļ���˼���ǣ������������й����һ���󶥶ѣ���ʱ����������
�����ֵ���ǶѶ��ĸ��ڵ㡣������ĩβԪ�ؽ��н�������ʱĩβ��Ϊ���ֵ��
Ȼ��ʣ��n-1��Ԫ�����¹����һ���ѣ�������õ�n��Ԫ�صĴ�Сֵ��
��˷���ִ�У����ܵõ�һ������������*/

void heapSort(int n){

    for(int k=n-1;k>=0;k--){//ÿһ��ѭ���Ĺ��̼�Ϊһ�ζѵĹ�����ÿ�ζ�����ǰ������Ԫ�ظ������Ѷ�
        for(int i=k/2;i>=0;i--){
            if(2*i+1<=k&&A[i]<A[2*i+1]){
                swap(A[i],A[2*i+1]);
            }
            if(2*i+2<=k&&A[i]<A[2*i+2])
                swap(A[i],A[2*i+2]);
        }
        swap(A[0],A[k]);//�����Ľ��ֱ�Ӳ嵽����β�����ں����ĸ��¹����н����ڸ��������β��
    }

}


/**�鲢����*/

int temp[10];//�м�����

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

/**��������*/
/*����ÿһ�����ĴӸ�λ����λ����Ϣ��������*/

/**Ͱ����*/
/*�����ݰ���Χ��Ϊ���飬ÿһ�鶼����һ����Χ�����Խ�ÿһ�鿴��һ��Ͱ��Ȼ����Ͱ�ڽ�������*/

/**��������*/
/*�����ݵķ�Χ��֪�Ҳ����ر���ʱ�򣬿��Բ���һ��������ͳ��ÿһ��Ԫ�س��ֵĴ�����
����������±���ǵ�ǰԪ�ص�ֵ*/

void countSort(int n){
    int counter[101];//������������С��100
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

/**˯������*/
/*��ÿһ��������Ϊһ�����̵�˯��ʱ����Ȼ����ݽ������ѵ��Ⱥ�˳������������*/

/**������*/
/*����������������ң��ж��Ƿ�����������裬�����´���-��-�Ǻǣ���һ�ºܿ���*/


int main()
{
//  insertSort(10);
    mergeSort(0,9);
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    cout<<endl;

}

