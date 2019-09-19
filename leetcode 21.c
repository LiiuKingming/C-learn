struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
 
   struct ListNode* newHead,*newTail;

    if(l1 == NULL){

        return l2;

    }

    if(l2 == NULL){

        return l1;

    }//找头

    if(l1->val < l2->val){

        newHead = l1;

        l1 = l1->next;

    }else{

        newHead = l2;

        l2 = l2->next;

    }
    
    //合并
    
    newTail = newHead;

    while(l1 && l2){//都不为NULL

        if(l1->val < l2->val){

            newTail->next = l1;

            l1 = l1->next;

        }else{

            newTail->next = l2;

            l2 = l2->next;

        }

        newTail = newTail->next;

    }
    //捡漏
    if(l1)
 
       newTail->next = l1;

    
    if(l2)
 
       newTail->next = l2;

    
    return newHead;

}