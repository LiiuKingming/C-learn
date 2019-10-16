struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev , *cur ,*next;
    if(head == NULL || head->next == NULL){
        return head;
    }
    prev = NULL;
    cur = head;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head){
    //找到中间位置,从中间开始逆置
    struct ListNode* fast , *slow ,*rList ;
    if(head == NULL || head->next == NULL)
        return true;
    fast = slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //逆置后半部分链表
    rList = reverseList(slow);
    //对应位置比较
    while(head && rList){
        if(rList->val != head->val)
            return false;
        rList = rList->next;
        head = head->next;
    }
    return true;
}