# 程序员代码面试指南：IT名企算法与数据结构题目最优解

**wyf, 2019-9.24** 

&emsp; &emsp;本项目用于复现**左程云老师**书籍《**程序员代码面试指南:IT名企算法与数据结构题目最优解**》(第二版)中算法代码。[书中代码](http://www.broadview.com.cn/book/4889)均采用Java实现，并采用面向对象方式进行封装(风格类似于LeetCode)。本人参照作者思路(可能会有些许变动)，使用C++进行编程复现。编写的代码均可在[牛客网评测系统](https://www.nowcoder.com/ta/programmer-code-interview-guide)中成功通过测试。:arrow_down: 

![Cover](./Cover.jpg)

## 常用数据结构的实现

&emsp;&emsp;本块主要列举书中所涉数据结构的实现。其中部分数据结构尝试使用C++或python手编实现(可能并不整洁高效,demo版)，也有数据结构可直接调用C++ STL(标准模板库)实现，具体用法可见官方文档。

| 对应章节 | 数据结构 |                         STL官方文档                          |         实现方式(demo版)         |
| :------: | :------: | :----------------------------------------------------------: | :------------------------------: |
|    1     |    栈    |   [stack](http://www.cplusplus.com/reference/stack/stack/)   |    [Python](ADT_py/Stack.py)     |
|    1     |   队列   |   [queue](http://www.cplusplus.com/reference/queue/queue/)   |    [Python](ADT_py/Queue.py)     |
|    1     | 双端队列 |   [deque](http://www.cplusplus.com/reference/deque/deque/)   |    [Python](ADT_py/Deque.py)     |
|    2     |   链表   |    [list](http://www.cplusplus.com/reference/list/list/)     | [C++](ADT_cpp/LinkList_demo.cpp) |
|    5     |  字符串  | [C++ String类](http://www.cplusplus.com/reference/string/string/) |                                  |

</br>

## 第一章：栈与队列

| 序号 |                             题目                             |  难度   |  完成时间  |                          实现                           |     标签     |
| :--: | :----------------------------------------------------------: | :-----: | :--------: | :-----------------------------------------------------: | :----------: |
|  1   | [设计getMin功能的栈](https://www.nowcoder.com/practice/05e57ce2cd8e4a1eae8c3b0a7e9886be?tpId=101&tqId=33073&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    1    | 2019-9.24  |           [C++](CH1_Stack_Queue/1_getMin.cpp)           |    栈设计    |
|  2   | [使用两个栈模拟队列](https://www.nowcoder.com/practice/6bc058b32ee54a5fa18c62f29bae9863?tpId=101&tqId=33074&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    2    | 2019-9.24  |        [C++](CH1_Stack_Queue/2_stack_queue.cpp)         |    栈设计    |
|  3   | [用递归函数和栈逆序一个栈](https://www.nowcoder.com/practice/1de82c89cc0e43e9aa6ee8243f4dbefd?tpId=101&tqId=33075&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    2    | 2019-9.26  | [C++](CH1_Stack_Queue/3_Inverse_Stack_by_Recursion.cpp) |     递归     |
|  4   | [猫狗队列](https://www.nowcoder.com/practice/8a7e04cff6a54b7095b94261d78108f5?tpId=101&tqId=33168&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    1    | 2019-10.3  |       [C++](CH1_Stack_Queue/4_Dog_Cat_Queue.cpp)        |    大模拟    |
|  5   | [用一个栈实现另一个栈的排序](https://www.nowcoder.com/practice/ff8cba64e7894c5582deafa54cca8ff2?tpId=101&tqId=33081&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    1    | 2019-9.28  |         [C++](CH1_Stack_Queue/5_Sort_Stack.cpp)         |    栈设计    |
|  6   | [用栈来求解汉诺塔问题](https://www.nowcoder.com/practice/1a2f618b3433487295657b3414f4e7c4?tpId=101&tqId=33090&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    3    | 2019-10.8  |      [C++](CH1_Stack_Queue/6a_Hanoi_Recursive.cpp)      |     递归     |
|  7   | [生成窗口最大值数组](https://www.nowcoder.com/practice/b316c7f9617744b98fa311ae29ac516c?tpId=101&tqId=33083&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    2    | 2019-10.6  |     [C++](CH1_Stack_Queue/7_Max_Windows_Array.cpp)      |   双端队列   |
| 8.a  | [单调栈结构--基础](https://www.nowcoder.com/practice/e3d18ffab9c543da8704ede8da578b55?tpId=101&tqId=33169&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    2    | 2019-10.11 |      [C++](CH1_Stack_Queue/8b_Monotate_Stack.cpp)       |    单调栈    |
| 8.b  | [单调栈结构--进阶](https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb?tpId=101&tqId=33256&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    3    | 2019-10.13 |      [C++](CH1_Stack_Queue/8c_Monotate_Stack.cpp)       |   数据组织   |
|  9   | [最大子矩阵](https://www.nowcoder.com/practice/ed610b2fea854791b7827e3111431056?tpId=101&tqId=33084&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    3    | 2019-10.15 |       [C++](CH1_Stack_Queue/9_Max_SubMatrix.cpp)        |  单调栈应用  |
|  10  | [最大值减最小值<=num的子数组数量](https://www.nowcoder.com/practice/5fe02eb175974e18b9a546812a17428e?tpId=101&tqId=33086&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    3    | 2019-10.17 |        [C++](CH1_Stack_Queue/10_Max_Min_Num.cpp)        | 双端队列应用 |
| 11.a | [可见山峰对数--基础](https://www.nowcoder.com/practice/80d076bcea594b86ba55b913de4c069d?tpId=101&tqId=33170&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) | **inf** |    ...     |       [C++](CH1_Stack_Queue/11_Mountain_Num.cpp)        |  数学智力题  |
| 11.b | [可见山峰对数--进阶](https://www.nowcoder.com/practice/16d1047e9fa54cea8b5170b156d89e38?tpId=101&tqId=33173&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |    4    |            |                                                         |  单调栈应用  |

</br>

## 第二章：链表

| 序号 |                             题目                             | 难度 |  完成时间  |                       实现                        |   标签   |
| :--: | :----------------------------------------------------------: | :--: | :--------: | :-----------------------------------------------: | :------: |
|  1   | [打印两个有序链表的公共部分](https://www.nowcoder.com/practice/8943eea40dbb4185b187d80fd050fee9?tpId=101&tqId=33116&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  1   | 2019-10.17 |     [C++](CH2_LinkedList/1_Overlap_List.cpp)      | 链表遍历 |
|  2   | [删除链表倒数第K个节点](https://www.nowcoder.com/practice/e5d90aac4c8b4628aa70d9b6597c0560?tpId=101&tqId=33117&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  1   | 2019-10.19 |     [C++](CH2_LinkedList/2_Delete_Lastk.cpp)      | 链表遍历 |
|  3   |                       删除链表中间节点                       |  1   | 2019-10.19 |     [C++](CH2_LinkedList/3_Delete_Medium.cpp)     | 链表遍历 |
|  4   | [反转单向和双向链表](https://www.nowcoder.com/practice/b66a251dec8847f386bbe6cd96b7e9c8?tpId=101&tqId=33175&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  1   | 2019-10.19 |  [C++](CH2_LinkedList/4_Reverse_LinkedList.cpp)   | 链表遍历 |
|  5   | [反转部分单链表](https://www.nowcoder.com/practice/f11155006f154419b0bef6de8918aea2?tpId=101&tqId=33176&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking) |  1   | 2019-10.21 | [C++](CH2_LinkedList/5_Reverse_SubLinkedList.cpp) | 链表遍历 |
| 6.a  | [环形链表的约瑟夫问题--基础](https://www.nowcoder.com/practice/c3b34059faf546d3a7ee28f2b0154286?tpId=101&tqId=33177&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking) |  1   |            |                                                   |          |

</br>

