#include <iostream>
#include <string>

#define N 1000000+5
#define M 10000+5
using namespace std;



int Next[M];
string a,b;

void getNext(int m){//获得前缀后缀的最长长度,其中Next[i]表示b[0,..,i-1]的最长前缀后缀的长度。

    int i=0,j=-1;

    Next[0]=-1;//注意初始化

    while(i<m){
        if(j==-1||b[i]==b[j]){
            i++;
            j++;
            Next[i]=j;//递推
        }
        else{
            j = Next[j];//类似于kmp的回退
        }
    }


}


int KMP(int lenA,int lenB){

    //KMP算法，但发生不匹配的时候文本串的指针不同，模式串的指针根据Next数组进行移动
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
