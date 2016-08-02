ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode (INT_MIN);
        ListNode *cur = head;
        
        while (cur) {
            ListNode *cur_next = cur->next;
            
            ListNode *iter = dummy;
            while (iter->next && iter->next->val < cur->val) {
                iter = iter->next;
            } // terminated by iter < cur < iter->next
            cur->next = iter->next;// Cut off last node's connection automatically!!
            iter->next = cur;
            
            cur = cur_next;
        }
        
        return dummy->next;
    }
