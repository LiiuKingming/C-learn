

struct ListNode* middleNode(struct ListNode* head){
    size_t n = 0;
    struct ListNode* cur;
    if(head == NULL)
        return head;
    cur = head;
    while(cur){
        n++;
        cur = cur->next;
    }
    n /= 2;
    cur = head;
    while(n--){
        cur = cur->next;
    }
    return cur;
}

