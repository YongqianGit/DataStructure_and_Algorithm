    int length(ListNode *head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }

ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {return head;}
        
        int len = length(head);
        k %= len;
        
        if (k == 0) return head;
        
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        ListNode* cur = head, *prev = dummy;
        int cnt = 0;
        ListNode *new_h = head;
        while ( cur ) {
            prev = cur;
            cur = cur->next;
            if (++cnt == len - k) {
                prev->next = NULL;
                new_h = cur;
            }
        }
        
        prev->next = head;
        
        return new_h;
    }
