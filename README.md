# 程序员代码面试指南：IT名企算法与数据结构题目最优解

**wyf, 2019-9.24**

&emsp; &emsp;本项目用于复现**左程云老师**书籍《**程序员代码面试指南：IT名企算法与数据结构题目最优解**》(第二版)中算法题目的代码。[书中代码](http://www.broadview.com.cn/book/4889)均采用Java实现，并采用面向对象方式进行封装(类似于LeetCode)。本人参照书中左程云老师的思路(可能会有些许变动)，并使用C++进行编程复现。编写的代码均可在[牛客网评测系统](https://www.nowcoder.com/ta/programmer-code-interview-guide)中成功通过测试。

![Cover](./Cover.jpg)

**注**：本人采用C++实现时，给出的代码均为面向过程式编程风格(类似于ACM)，但部分题目本人也采用了面向对象的编程风格(类似于LeetCode)，详见每章的代码文件夹。

## 常用数据结构的实现

&emsp;&emsp;本节主要列举书中涉及到的数据结构的实现。其中某些数据结构直接使用C++ STL(标准模板库)，本人就暂时不贴代码(具体用法可见官方文档)。其他数据结构则自己手编实现。(待更新)

| 对应章节 | 数据结构 | 实现方式 |                           参考链接                           |
| :------: | :------: | :------: | :----------------------------------------------------------: |
|    1     |    栈    |   STL    | [stack官方文档](http://www.cplusplus.com/reference/stack/stack/) |
|    1     |   队列   |   STL    | [queue官方文档](http://www.cplusplus.com/reference/queue/queue/) |
|    1     | 双端队列 |   STL    | [deque官方文档](http://www.cplusplus.com/reference/deque/deque/) |



## 第一章：栈与队列

| 序号 |                             题目                             | 难度 | 完成时间  |                          实现                           |      备注      |                           参考资料                           |
| :--: | :----------------------------------------------------------: | :--: | :-------: | :-----------------------------------------------------: | :------------: | :----------------------------------------------------------: |
|  1   | [设计getMin功能的栈](https://www.nowcoder.com/practice/05e57ce2cd8e4a1eae8c3b0a7e9886be?tpId=101&tqId=33073&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  1   | 2019-9.24 |           [C++](CH1_Stack_Queue/1_getMin.cpp)           | 时间复杂度优化 |                                                              |
|  2   | [使用两个栈模拟队列](https://www.nowcoder.com/practice/6bc058b32ee54a5fa18c62f29bae9863?tpId=101&tqId=33074&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  2   | 2019-9.24 |        [C++](CH1_Stack_Queue/2_stack_queue.cpp)         |                |                                                              |
|  3   | [用递归函数和栈操作逆序一个栈](https://www.nowcoder.com/practice/1de82c89cc0e43e9aa6ee8243f4dbefd?tpId=101&tqId=33075&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  2   | 2019-9.26 | [C++](CH1_Stack_Queue/3_Inverse_Stack_by_Recursion.cpp) |     分两步     |                                                              |
|  4   | [猫狗队列](https://www.nowcoder.com/practice/8a7e04cff6a54b7095b94261d78108f5?tpId=101&tqId=33168&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  1   | 2019-10.3 |       [C++](CH1_Stack_Queue/4_Dog_Cat_Queue.cpp)        |     大模拟     |                                                              |
|  5   | [用一个栈实现另一个栈的排序](https://www.nowcoder.com/practice/ff8cba64e7894c5582deafa54cca8ff2?tpId=101&tqId=33081&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  1   | 2019-9.28 |         [C++](CH1_Stack_Queue/5_Sort_Stack.cpp)         |                |                                                              |
|  6   | [用栈来求解汉诺塔问题](https://www.nowcoder.com/practice/1a2f618b3433487295657b3414f4e7c4?tpId=101&tqId=33090&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  3   | 2019-10.8 |      [C++](CH1_Stack_Queue/6_Hanoi_Recursive.cpp)       |    思考递归    |                                                              |
|  7   | [生成窗口最大值数组](https://www.nowcoder.com/practice/b316c7f9617744b98fa311ae29ac516c?tpId=101&tqId=33083&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  2   | 2019-10.6 |     [C++](CH1_Stack_Queue/7_Max_Windows_Array.cpp)      | 时间复杂度优化 | [博客笔记](http://blog.itpub.net/31561266/viewspace-2286701/) |



## 第二章：链表





