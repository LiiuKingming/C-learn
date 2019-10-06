bool hasCycle(struct ListNode *head) {
    struct ListNode* fast,*slow;
    if(head == NULL)
        return false;
    slow = fast = head;
    while(fast && fast->next){
        //�������жϱ�������
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        } 
    }
    return false;
}