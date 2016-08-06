private:
    stack<int> sk, sk_min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if ( sk_min.empty() || x <= sk_min.top() ) {
            sk_min.push(x);
        }
        sk.push(x);
    }
    
    void pop() {
        if (sk.top() == sk_min.top() ) {
            sk_min.pop();
        }
        sk.pop();
    }
    
    int top() {
        return sk.top();
    }
    
    int getMin() {
        return sk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
