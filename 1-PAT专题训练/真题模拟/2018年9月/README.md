## 2018年9月真题

-----

用时(03:00:00)

- 1144：如果可以直接遍历答案最好直接遍历，不要遍历其他的东西，可以避免出错。
- 1145：这道题很凉，一开始对于散列的冲突堆积中二次探测是什么意思了，而且第一眼看到Quadratic Probing这个词心理是懵逼的。(然后就根据自己脑补的方法，把给的那个样例给凑对了，然后事实证明，算法的东西容不得纠结和马虎，题意还是没有把握对)最后看了一番题解感觉题目也不是特别的清楚。为什么后面查询的时候二次探测的探针j的取值范围是[0,TSize]呢？为啥不是[0,TSize-1]呢？
- 1146：拓扑排序的题，采用一个set存储入度为0的结点（写代码的时候，记住，如果写状态是需要重复多次进行使用的，那么就不要改变他的状态，直接先把它赋值给一个临时变量，不要犯这种低级的错误）
- 1147：这道题感觉是1155的初级版本，根据层次遍历的序列(完全二叉树)构建出二叉树对应的堆，然后判断是否为堆？最大堆还是最小堆？最后再输出后续遍历的结果就可以了。
