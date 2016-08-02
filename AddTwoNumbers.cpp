ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = 0;
        ListNode *dummy = new ListNode (-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            carry += l1->val + l2->val;
            cur->next = new ListNode (carry % 10);
            carry /= 10;
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }
        
        while (l1) {
            carry += l1->val;
            cur->next = new ListNode (carry % 10);
            carry /= 10;
            l1 = l1->next;
            cur = cur->next;
        }
        
        while (l2) {
            carry += l2->val;
            cur->next = new ListNode (carry % 10);
            carry /= 10;
            l2 = l2->next;
            cur = cur->next;
        }
        
        if (carry != 0) {
            cur->next = new ListNode (1);
        }
        
        return dummy->next;
    }
