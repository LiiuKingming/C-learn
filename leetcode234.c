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
    //�ҵ��м�λ��,���м俪ʼ����
    struct ListNode* fast , *slow ,*rList ;
    if(head == NULL || head->next == NULL)
        return true;
    fast = slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //���ú�벿������
    rList = reverseList(slow);
    //��Ӧλ�ñȽ�
    while(head && rList){
        if(rList->val != head->val)
            return false;
        rList = rList->next;
        head = head->next;
    }
    return true;
}