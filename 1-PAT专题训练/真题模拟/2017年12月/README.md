

Revise:

- 1136 : 输入的数小于1000位，所以必须采用大数加法.只用long long类型最后一共用例过不了。

- 1137 ：最后一个样例始终过不了

- 1138 ：可以建树然后得到后续遍历的序列，输出第一个元素。（这里可以在建树的过程中加入标记，一旦找到定一个元素便可以停止递归）。

- 1139 ：二维map，错了不少的用例，可能理解有些偏差。①找到的friend要保证不是自己的lover ②id要采用string来存储，因为输出的时候0001用int就变成了1，同时如果是-0000和0000就没办法通过正负和大小区分性别了。③以空间换时间，采用邻接链表的结构存储所有结点的同性朋友，节省遍历的时间消耗。
