ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *dummy = new ListNode (head->val - 1);
        dummy->next = head;
        ListNode *cur = head, *prev = dummy;
        bool rep = false;
        
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur = cur->next;
                rep = true;
            }
            else {
                if (rep) {
                    prev->next = cur->next;
                    rep = false;
                    // Do NOT move prev yet!!! cur->next->next may be repeated of cur->next!!!
                }
                else {
                    prev = cur;
                }
                cur = cur->next;
            }
        }
        
        if (rep) {
            prev->next = cur->next;
        }
        return dummy->next;
    }
