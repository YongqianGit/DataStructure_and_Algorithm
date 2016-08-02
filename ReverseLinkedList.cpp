ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while (head) {
            ListNode *cur_next = head->next;
            head->next = prev;
            prev = head;
            head = cur_next;
        }
        
        return prev;
    }
