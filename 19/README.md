# LeetCode-19 删除链表的倒数第N个结点

## 题目描述
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。  

示例：

    给定一个链表: 1->2->3->4->5, 和 n = 2.  
    当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：  
给定的 n 保证是有效的。

进阶：  
你能尝试使用一趟扫描实现吗？

## 解决方案
### 方法一：两次遍历算法  
我看到题目想到的就是这种方法，相信大部分人跟我是一样的，这个算法原理简单，但实现起来还是有些细节需要注意的，特别是leetcode给出的函数有一个坑，这里的头结点head跟我们平常用的不太一样，这里的head是带数据域的，也即head既是头结点，又是第一个数据结点；下面说说思路：  

这个问题可以简化成另一个问题：删除从列表开头数起的第 (L - n + 1) 个结点，其中 L 是列表的长度。只要我们找到列表的长度 L，这个问题就很容易解决。

算法：  

首先我们将添加一个哑结点作为辅助，该结点位于列表头部。哑结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部。在第一次遍历中，我们找出列表的长度 L。然后设置一个指向哑结点的指针，并移动它遍历列表，直至它到达第 (L - n) 个结点那里。我们把第 (L - n) 个结点的 next 指针重新链接至第 (L - n + 2) 个结点，完成这个算法。  

代码详解：

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p, *q;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));  //申请一个哑结点
    p->next = head;             //哑结点的后驱指针指向头结点next
    q = head;                   //q指向头结点
    int length = 0;             //初始化结点个数为0
    
	while(q != NULL)            //计算结点个数
    {
        length ++;
        q = q->next;
    }
    
    length = length - n;        
    q = p;                      //q指向哑结点
    while(length >0)            //遍历q到第 length-n 个结点
    {
        length --;
        q = q->next;
    }
    
    q->next = q->next->next;   //删除第 length-n+1 个结点
    return p->next;            //返回头结点
}
```

### 方法二：一次遍历算法  

算法：  
上述算法可以优化为只使用一次遍历。我们可以使用两个指针而不是一个指针。第一个指针从列表的开头向前移动 n+1 步，而第二个指针将从列表的开头出发。现在，这两个指针被 n 个结点分开。我们通过同时移动两个指针向前来保持这个恒定的间隔，直到第一个指针到达最后一个结点。此时第二个指针将指向从最后一个结点数起的第 n 个结点。我们重新链接第二个指针所引用的结点的 next 指针指向该结点的下下个结点。

可能大家觉得不好理解，我推荐直接看代码，顺着代码写一篇流程就可以明白了。

代码详解：  

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = head;
    
    struct ListNode *first = p, *second = p;
    for(int i=1; i<=n+1; i++)
    {
        first = first->next;
    }
    
    while(first)
    {
        first = first->next;
        second = second->next;
    }
    
    second->next = second->next->next;
    return p->next;
}
```
最后说一下，这两种算法提交后，执行用时以及内存消耗都是一样一样的，所以，记第一种吧。