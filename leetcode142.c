struct ListNode *hashCycle(struct ListNode *head){
    struct ListNode* fast,*slow;
    fast = slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return slow;
    }
    return NULL;
}

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* head1,*slow;
    if(head == NULL)
        return head;
    //ÕÒµ½ÏàÓöµã
    slow = hashCycle(head);
    head1 = head;
    if(slow){
        while(slow != head1){
            slow = slow->next;
            head1 = head1->next;
        }
        return slow;
    }
    return NULL;
}