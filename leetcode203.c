

struct ListNode* removeElements(struct ListNode* head, int val){
    
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while(cur){
        if(cur->val == val){
            if(prev == NULL){
                head = cur->next;  
                free(cur);
                cur = head;
            }else{
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
           
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}
