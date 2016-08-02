ListNode* reverseBetween0(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        ListNode *cur = dummy, *prev = cur;
        
        int cnt = 0;
        while (++cnt <= m) {
            prev = cur;
            cur = cur->next;
        }
        
        ListNode *unrev_prev = prev, *rev_end = cur;
        
        while (cnt++ <= n + 1) {
            ListNode *cur_next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = cur_next;
        } // prev is head of reversed part
        
        unrev_prev->next = prev;
        rev_end->next = cur;
        
        return dummy->next;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        ListNode *cur = head, *prev = dummy;
        ListNode *rev_end = cur, *unrev_prev = prev;
        
        int cnt = 1;
        
        while (cur) {
            if (cnt == m) {
                unrev_prev = prev;
                rev_end = cur;
            }
            
            if (cnt >= m && cnt <= n) {
                ListNode *cur_next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = cur_next;
            }
            else if (cnt < m) {
                prev = cur;
                cur = cur->next;
            }
            else { // cnt > n
                break;
            }
            
            cnt++;
        }// prev is head of reversed part
        
        unrev_prev->next = prev;
        rev_end->next = cur;
        
        return dummy->next;
        
    }
