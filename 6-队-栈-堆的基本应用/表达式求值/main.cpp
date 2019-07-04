/*
实现中缀表达式的计算求值
步骤总览:
    中缀表达式->后缀表表达式->利用操作数栈辅助求值

中缀表达式->后缀表达手：

step1: 声明符号栈S，从左到右扫描输入的字符串，得到当前字符c

step2: if c is digit:
       then c加入到后缀表达式的输出中

step3: if c is '(':
       then c S.push(c)

step4: if c is ')':
       逐一弹出S中的元素加入到后缀表达式的输出中，知道遇到'('为止，并将其丢弃

step5: while(c is 操作符)
           if 栈顶为空 或者 S.top为'(' 或者 c的优先级比S.top高
                S.push(c)
                break
           else
                弹出栈顶元素加入到后缀表达式的输出中

step6: 跳转到step1,直到字符串扫描结束为止

step7: 如果此时栈S仍不为空,则将栈内的元素逐一弹出,加入到后缀表达式的输出中



后缀表表达式->利用操作数栈辅助求值：

维护一个数字栈S
扫描得到的后缀表达式的字符串
    if(当前字符为数字)
        S.push(当前数字)
    else//当前字符为操作符(这里需要注意运算时操作数的顺序)
        根据操作符运算所需的操作数个数，弹出栈顶元素进行运算
        并将运算的结果压入到栈中

字符串识别结束后，栈内只有一个元素，即运算的结果。
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

    string src="",tar="";//src为中缀表达式，tar为后缀表达式

    cin>>src;
    int len = src.size();

    //中缀表达式转为后缀表达式
    for(int i=0;i<len;i++){//扫描输入的字符串
        if(src[i]<='9'&&src[i]>='0')//当输入为操作数时
            tar += src[i];
        else if(src[i]=='(')//当输入为左括号时
            Op.push(src[i]);
        else if(src[i]==')'){//当输入为右括号时
            while(Op.top()!='('){
                    tar+=Op.top();
                    Op.pop();
            }
            Op.pop();
        }
        while(isOp(src[i])){//当输入为操作符时
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
    while(Op.size()!=0){//当输入结束时，如果栈内还有元素的话
        tar+=Op.top();
        Op.pop();
    }
    cout<<tar<<endl;

    //后缀表达式求值
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
            else if(tar[i]=='-'){//注意操作数的运算顺序
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(num2-num1);
            }
            else if(tar[i]=='*'){
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(num1*num2);
            }
            else if(tar[i]=='/'){//注意操作数的运算顺序
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(num2/num1);
            }
            else if(tar[i]=='^'){//注意操作数的运算顺序
                num1=Num.top(),Num.pop();
                num2=Num.top(),Num.pop();
                Num.push(power(num2,num1));
            }
            else if(tar[i]=='!'){//注意操作数的运算顺序
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








