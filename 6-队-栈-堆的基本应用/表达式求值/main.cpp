/*
ʵ����׺���ʽ�ļ�����ֵ
��������:
    ��׺���ʽ->��׺����ʽ->���ò�����ջ������ֵ

��׺���ʽ->��׺����֣�

step1: ��������ջS��������ɨ��������ַ������õ���ǰ�ַ�c

step2: if c is digit:
       then c���뵽��׺���ʽ�������

step3: if c is '(':
       then c S.push(c)

step4: if c is ')':
       ��һ����S�е�Ԫ�ؼ��뵽��׺���ʽ������У�֪������'('Ϊֹ�������䶪��

step5: while(c is ������)
           if ջ��Ϊ�� ���� S.topΪ'(' ���� c�����ȼ���S.top��
                S.push(c)
                break
           else
                ����ջ��Ԫ�ؼ��뵽��׺���ʽ�������

step6: ��ת��step1,ֱ���ַ���ɨ�����Ϊֹ

step7: �����ʱջS�Բ�Ϊ��,��ջ�ڵ�Ԫ����һ����,���뵽��׺���ʽ�������



��׺����ʽ->���ò�����ջ������ֵ��

ά��һ������ջS
ɨ��õ��ĺ�׺���ʽ���ַ���
    if(��ǰ�ַ�Ϊ����)
        S.push(��ǰ����)
    else//��ǰ�ַ�Ϊ������(������Ҫע������ʱ��������˳��)
        ���ݲ�������������Ĳ���������������ջ��Ԫ�ؽ�������
        ��������Ľ��ѹ�뵽ջ��

�ַ���ʶ�������ջ��ֻ��һ��Ԫ�أ�������Ľ����
*/

#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;


stack<char> Op;

map<int,int> prior;

bool isOp(char c){
    if(c=='-'||c=='+'||c=='*'||c=='/'||c=='^'||c=='!')
        return true;
    else
        return false;
}

int jiechen(int n){
    int x=1;
    for(int i=1;i<=n;i++){
        x*=i;
    }
    return x;
}

int power(int x,int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=x;
    }
    return ans;
}

int main()
{

    prior['+'] = 1,prior['-'] = 1,prior['*'] = 2,prior['/'] = 2,prior['^'] = 3,prior['!']=4;

    string src="",tar="";//srcΪ��׺���ʽ��tarΪ��׺���ʽ

    cin>>src;
    int len = src.size();

    //��׺���ʽתΪ��׺���ʽ
    for(int i=0;i<len;i++){//ɨ��������ַ���
        if(src[i]<='9'&&src[i]>='0')//������Ϊ������ʱ
            tar += src[i];
        else if(src[i]=='(')//������Ϊ������ʱ
            Op.push(src[i]);
        else if(src[i]==')'){//������Ϊ������ʱ
            while(Op.top()!='('){
                    tar+=Op.top();
                    Op.pop();
            }
            Op.pop();
        }
        while(isOp(src[i])){//������Ϊ������ʱ
            if(Op.size()==0||Op.top()=='('||prior[Op.top()]<prior[src[i]]){
                Op.push(src[i]);
                break;
            }
            else{
                tar+=Op.top();
                Op.pop();
            }
        }
    }
    while(Op.size()!=0){//���������ʱ�����ջ�ڻ���Ԫ�صĻ�
        tar+=Op.top();
        Op.pop();
    }
    cout<<tar<<endl;

    //��׺���ʽ��ֵ
    int lentar = tar.size();

    stack<int> Num;
    for(int i=0;i<lentar;i++){
        if(tar[i]<='9'&&tar[i]>='0'){
            Num.push(tar[i]-'0');
        }
        else{
            int num1,num2;
            if(tar[i]=='+'){
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(num1+num2);
            }
            else if(tar[i]=='-'){//ע�������������˳��
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(num2-num1);
            }
            else if(tar[i]=='*'){
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(num1*num2);
            }
            else if(tar[i]=='/'){//ע�������������˳��
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(num2/num1);
            }
            else if(tar[i]=='^'){//ע�������������˳��
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(power(num2,num1));
            }
            else if(tar[i]=='!'){//ע�������������˳��
                num1=Num.top(),Num.pop();
                Num.push(jiechen(num1));
            }
        }
    }
    cout<<Num.size()<<endl;
    cout<<"The result is:"<<Num.top()<<endl;

    return 0;
}
/*
(3^2/(2+1))-3*(4-5)+2!
1+2!-3*(4-5)
1+2*(3-4)-5*6
*/








