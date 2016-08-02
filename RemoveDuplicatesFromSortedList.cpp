ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {return head;}
        ListNode *cur = head, *prev = head;
        while (cur && cur->next) {
            if (cur->val != cur->next->val) {
                prev->next = cur->next;
                prev = prev->next;
            }
            cur = cur->next;
        }
        
        prev->next = NULL;
        
        
        return head;
    }
