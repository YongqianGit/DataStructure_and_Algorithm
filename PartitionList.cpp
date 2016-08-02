ListNode* partition(ListNode* head, int x) {
        ListNode *cur = head;
        ListNode *dummy_ge = new ListNode (-1), *dummy_lt = new ListNode (-1);
        ListNode *ge = dummy_ge, *lt = dummy_lt;
        
        while(cur) {
            if (cur->val < x) {
                lt->next = cur;
                lt = cur;
            }
            else {
                ge->next = cur;
                ge = cur;
            }
            cur = cur->next;
        }
        ge->next = NULL; // CUT off!!!
        
        lt->next = dummy_ge->next;
        
        return dummy_lt->next;
    }
