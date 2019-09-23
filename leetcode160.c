struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //ͳ��������
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
    }//���㳤�Ȳ�gap
    gap = abs(lenA - lenB);
    shortL = headA;
    longL = headB;
    if(lenA > lenB){
        shortL = headB;
        longL = headA;
    }//����������gap��
     while(gap--){
        longL = longL->next;
    }//��������ͬʱ��
    while(longL && shortL){
        if(shortL == longL){
            return longL;
        }
        longL = longL->next;
        shortL = shortL->next;
    }
    return NULL;
}