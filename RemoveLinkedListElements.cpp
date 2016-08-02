ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        ListNode *cur = dummy;
        
        while (cur && cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next; // cur cannot move forward ye because cur->next is updated!!
            }
            else {
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
