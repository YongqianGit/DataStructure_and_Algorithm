ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        ListNode *front = head, *back = dummy;
        while (cnt++ < n) {
            front = front->next;
        }
        
        while (front) {
            back = back->next;
            front = front->next;
        }
        
        back->next = back->next->next;
        
        return dummy->next;
    }
