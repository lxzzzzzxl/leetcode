/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = l1, *q = l2;
    struct ListNode *k = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *j =k;
    int x, y, sum, carry = 0;
    while(p != NULL || q != NULL)
    {
        x = (p!=NULL) ? p->val : 0;
        y = (q!=NULL) ? q->val : 0;
        sum = x+y+carry;
        carry = sum/10;
        j->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        j->next->val = sum%10;
        j = j->next;
        
        if(p!=NULL) p = p->next;
        if(q!=NULL) q = q->next;
    }
    if(carry > 0)
    {
        j->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        j = j->next;
        j->val = carry;
    }
    j->next = NULL;
    return k->next;
}
