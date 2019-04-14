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