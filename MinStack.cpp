class MinStack {
private:
    stack<int> val, min_val;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        val.push(x);
        if (min_val.empty() || x <= min_val.top() ) {
       return min_val.top();
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
