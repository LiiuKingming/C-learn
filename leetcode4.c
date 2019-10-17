struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* prev,*cur,*next;
    if(head == NULL || head->next == NULL)
        return head;
    prev = NULL;
    cur = head;
    next = head->next;    
    while(next){
        if(cur->val != next->val){
            prev = cur;
            cur = next;
            next = next->next;
        }else{
            //找到第一个不相同的节点
            while(next && cur->val == next->val){
                next = next->next;
            }//删除所有重复的节点
            while(cur != next){
                struct ListNode* tmp = cur->next;
                free(cur);
                cur = tmp;
                
            }//重新链接prev,cur,next
            //判断是否为头结点
            if(prev == NULL)
                head = cur;
            else
                prev->next = next;        
            if(next)
                next = next->next;
        }
    }
    return head;
}