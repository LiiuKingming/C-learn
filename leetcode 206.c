struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next ;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }    
    return prev;
}

