ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {return NULL;}
        
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        
        if (slow != fast) {return NULL;}// NO cycle!
        
        slow = head;
        
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
