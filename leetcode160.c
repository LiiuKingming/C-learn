struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //统计链表长度
    int lenA , lenB , gap;
    struct ListNode* curA,*curB,*longL,*shortL;
    lenA = lenB = 0;
    curA = headA;
    curB = headB;
    while(curA){
        lenA++;
        curA = curA->next;
    }
    while(curB){
        lenB++;
        curB = curB->next;
    }//计算长度差gap
    gap = abs(lenA - lenB);
    shortL = headA;
    longL = headB;
    if(lenA > lenB){
        shortL = headB;
        longL = headA;
    }//长链表先走gap步
     while(gap--){
        longL = longL->next;
    }//两个链表同时走
    while(longL && shortL){
        if(shortL == longL){
            return longL;
        }
        longL = longL->next;
        shortL = shortL->next;
    }
    return NULL;
}