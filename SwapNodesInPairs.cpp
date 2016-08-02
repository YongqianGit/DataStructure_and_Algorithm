ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {return head;}
        
        ListNode *p_o = head, *p_e = head->next, *new_h = p_e;
        ListNode *prev_o = NULL;
        
        while (p_o && p_o->next) {
            ListNode *cur_next = p_o->next->next;
            p_e = p_o->next;
            
            if (prev_o) {
                prev_o->next = p_e;
            }
            p_e->next = p_o;
            
            prev_o = p_o;
            p_o = cur_next;
        }
        
        if (p_o) { // odd length
            prev_o->next = p_o;
        }
        else { // even length
            prev_o->next = NULL;
        }
        
        return new_h;
    }
