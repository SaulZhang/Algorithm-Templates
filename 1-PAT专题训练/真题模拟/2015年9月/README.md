### 2015年9月真题

- 1109 ： 可以采用vector<int> vec来模拟双端队列，在头部插入元素x可以采用vec.insert(vec.begin(),x)，在尾部插入则为vec.push_back(x).



Revise：

- 1108 ：在不采用string类型的情况下，可以采用函数sscanf(a, "%lf", &temp)将字符数组a转为double类型输入到temp中。
然后采用函数sprintf(b, "%.2f",temp)可以将double类型的数据，以保留小数点后两位的格式输出到字符数组b中。
