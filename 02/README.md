# LeetCode-02 两数相加
## 题目表述

>给出两个**非空**的链表用来表示两个非负的整数。其中，它们各自的位数是按照**逆序**的方式存储的，并且它们的  每个节点只能存储**一位**数字。  
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。  
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807

## 解决方案

### 思路
使用变量跟踪进位，从最低位（表头）模拟逐位相加的过程。

### 算法
就像你在纸上计算两个数字的和那样，我们首先从最低有效位也就是列表 l1 和 l2 的表头开始相加。由于每位数字都应当处于 0到9 的范围内，我们计算两个数字的和时可能会出现“溢出”。例如，5 + 7 = 12。在这种情况下，我们会将当前位的数值设置为 2，并将进位 carry = 1 带入下一次迭代。进位 carry 必定是 0 或 1，这是因为两个数字相加（考虑到进位）可能出现的最大和为 9 + 9 + 1 = 19。  

伪代码如下：  
- 初始化返回链表的头结点k（这里使用头结点简化代码，你懂的。）
- 将p, q分别初始化为链表l1, l2的头部
- 初始化进位carry为0
- 将j指向头结点k
- 遍历l1, l2
     - 将 x 设为结点 p 的值。如果 p 已经到达 l1 的末尾，则将其值设置为 0。
     - 将 y 设为结点 q 的值。如果 q 已经到达 l2 的末尾，则将其值设置为 0。
     - 设定 sum = x + y + carry。
     - 更新进位的值，carry = sum / 10。
     - 创建一个数值为 (sum % 10） 的新结点，并将其设置为当前结点的下一个结点，然后将当前结点前进到下一个结点。同时，将 p 和 q 前进到下一个结点。
- 检查 carry = 1 是否成立，如果成立，则向返回列表追加一个含有数字 1 的新结点。
- 返回头结点的下一个结点。

### 代码详解
```C

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = l1, *q = l2;       //p, q指向l1, l2头部
    struct ListNode *k = (struct ListNode *)malloc(sizeof(struct ListNode));    //初始化返回链表的头结点
    struct ListNode *j =k;      //j指向k
    int x, y, sum, carry = 0;   //初始化进位carry为0
    while(p != NULL || q != NULL)   //遍历两个链表
    {
        x = (p!=NULL) ? p->val : 0; //非空赋值
        y = (q!=NULL) ? q->val : 0;
        sum = x+y+carry;            //取相应两位及进位之和
        carry = sum/10;             //判断是否有进位
        j->next = (struct ListNode *)malloc(sizeof(struct ListNode));   //申请新结点
        j->next->val = sum%10;      //给新结点赋值
        j = j->next;                //前进到新结点
        
        if(p!=NULL) p = p->next;    //前进
        if(q!=NULL) q = q->next;
    }
    if(carry > 0)               //最终进位判断
    {
        j->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        j = j->next;
        j->val = carry;
    }
    j->next = NULL;         //加上这句防报错
    return k->next;         //返回头结点的下一个结点
}

```