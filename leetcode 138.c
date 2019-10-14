class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur,*nT,*nH;
        if(head == NULL)
            return head;
        //插入
        cur = head;
        while(cur){
            Node* next = cur->next;
            Node* copy = (Node*)malloc(sizeof(Node));
            copy->val = cur->val;
            cur->next = copy;
            copy->next = next;
            cur = next;
        }
        //更新random
        cur = head;
        while(cur){
            while(cur){
            Node* copy = cur->next;
            if(cur->random)
                copy->random = cur->random->next;
            else
                copy->random = NULL;
            
            cur = copy->next;
        }
            // Node* copy = cur->next;
            // while(copy){
            //     copy->random = cur->random->next;//
            //     cur = copy->next;
            //     if(cur)
            //         copy = cur->next;
            // }
        }
        //分拆链表
        cur= head;
        nH = nT = NULL;
        while(cur){
            Node* copy = cur->next;
            if(nH == NULL){
                nH = nT = copy;
            }else{
                nT->next = copy;
                nT = nT->next;
            }
            cur->next = copy->next;
            cur = cur->next;
        }
        return nH;
    }
};