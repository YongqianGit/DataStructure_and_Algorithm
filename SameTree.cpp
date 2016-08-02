bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            if (p || q) { // one null one not
                return false;
            }
            else { // both null
                return true;
            }
        }
        
        if (p->val != q->val) {return false;}
        if (!isSameTree(p->left, q->left) ) {return false;}
        if (!isSameTree(p->right, q->right) ) {return false;}
        
        return true; 
    }

// Non-recursive, preorder
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> nd_p, nd_q;
        nd_p.push(p);
        nd_q.push(q);
        
        while (!nd_p.empty() && !nd_q.empty() ) {
            p = nd_p.top(); nd_p.pop();
            q = nd_q.top(); nd_q.pop();
            
            if (!p && ! q) {continue;}
            if (!p || !q) {return false;}
            
            if (p->val != q->val) {return false;}
            
            nd_p.push(p->left);
            nd_q.push(q->left);
            
            nd_p.push(p->right);
            nd_q.push(q->right);
        }
        
        return true;
    }
