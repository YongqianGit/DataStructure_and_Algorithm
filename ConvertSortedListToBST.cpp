int length(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    TreeNode *gen_BST(ListNode* &head, int l, int r) {
        if (l > r || !head) {return NULL;}
        int m = l + (r - l) / 2;
        
        
        TreeNode *tr_l = gen_BST(head, l, m - 1);
        TreeNode *root = new TreeNode (head->val);
        head = head->next;
        TreeNode *tr_r = gen_BST(head, m + 1, r);
        
        root->left = tr_l;
        root->right = tr_r;
        
        return root;
    }

 TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {return NULL;}
        int len = length(head);
        return gen_BST(head, 0, len);
    }
