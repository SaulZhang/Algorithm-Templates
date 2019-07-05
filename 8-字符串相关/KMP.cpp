#include <iostream>
#include <string>

#define N 1000000+5
#define M 10000+5
using namespace std;



int Next[M];
string a,b;

void getNext(int m){//���ǰ׺��׺�������,����Next[i]��ʾb[0,..,i-1]���ǰ׺��׺�ĳ��ȡ�

    int i=0,j=-1;

    Next[0]=-1;//ע���ʼ��

    while(i<m){
        if(j==-1||b[i]==b[j]){
            i++;
            j++;
            Next[i]=j;//����
        }
        else{
            j = Next[j];//������kmp�Ļ���
        }
    }


}


int KMP(int lenA,int lenB){

    //KMP�㷨����������ƥ���ʱ���ı�����ָ�벻ͬ��ģʽ����ָ�����Next��������ƶ�
    int i=0,j=0;

    while(i<lenA&&j<lenB){

        if(j==-1||a[i]==b[j]){
            i++,j++;
        }
        else{
            j = Next[j];
        }
    }

    if(j==lenB)
        return i-j;
    else
        return -1;
}


int main()
{
    cin>>a>>b;
    int lenA = a.size();
    int lenB = b.size();
    getNext(lenB);

    cout<<KMP(lenA,lenB)<<endl;


    return 0;
}
/*
cascabababacsc
ababab
*/
