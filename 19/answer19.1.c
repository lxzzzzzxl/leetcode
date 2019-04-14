/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p, *q;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = head;
    q = head;
    int length = 0;
    
	while(q != NULL)
    {
        length ++;
        q = q->next;
    }
    
    length = length - n;
    q = p;
    while(length >0)
    {
        length --;
        q = q->next;
    }
    
    q->next = q->next->next;   
    return p->next;
}