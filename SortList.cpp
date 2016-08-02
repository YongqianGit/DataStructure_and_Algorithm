void quicksort(vector<ListNode*> &res, int l, int r) {
        if (l > r) {return;}
        
        int i_l = l, i_r = r + 1;
        ListNode* &pivot = res[l];
        
        while (true) {
            do {
                i_l++;
            } while (i_l < i_r && res[i_l]->val < pivot->val);
            
            do {
                i_r--;
            } while (res[i_r]->val > pivot->val );
            
            if (i_l >= i_r) {break;}
            swap(res[i_l], res[i_r]);
        }
        
        swap(res[i_r], res[l]);
        
        quicksort(res, l, i_r - 1);
        quicksort(res, i_r + 1, r);
    }

ListNode* sortList(ListNode* head) {
        
        if (!head || !head->next) {return head;}
        
        vector<ListNode*> res;
        while (head) {
            res.push_back(head);
            head = head->next;
        }
        
        quicksort(res, 0, res.size() - 1);
        
        for (int i = 0; i < res.size() - 1; i++) {
            res[i]->next = res[i+1];
        }
        
        res.back()->next = NULL;
        
        return res[0];
    }
