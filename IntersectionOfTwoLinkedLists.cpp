int length(ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        
        return cnt;
    }


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA), lenB = length(headB);
        
        if (lenA < lenB) {
            swap(headA, headB);
            swap(lenA, lenB);
        }
        
        int diff = lenA - lenB;
        
        while (diff-- > 0) {
            headA = headA->next;
        }
        
        while (headA) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
        
    }
