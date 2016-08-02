 ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *p_o = head, *p_e = NULL;
        ListNode *h_e = head->next, *e_prev = NULL, *o_prev = NULL;
        
        while (p_o && p_o->next) {
            ListNode *next_o = p_o->next->next;
            p_e = p_o->next;
            
            p_o->next = next_o;
            
            if (e_prev) e_prev->next = p_e;
            
            o_prev = p_o;
            e_prev = p_e;
            
            p_o = next_o;
            
        }
        
        if (p_o) { // odd length
            p_e->next = NULL; // cut off last even to last odd
            p_o->next = h_e;
        }
        else { // even length
            o_prev->next = h_e;
        }
        
        return head;
    }
