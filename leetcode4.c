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
            //�ҵ���һ������ͬ�Ľڵ�
            while(next && cur->val == next->val){
                next = next->next;
            }//ɾ�������ظ��Ľڵ�
            while(cur != next){
                struct ListNode* tmp = cur->next;
                free(cur);
                cur = tmp;
                
            }//��������prev,cur,next
            //�ж��Ƿ�Ϊͷ���
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