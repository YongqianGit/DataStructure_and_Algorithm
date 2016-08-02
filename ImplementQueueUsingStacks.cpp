class Queue {
private:
    stack<int> sk_front, sk_back;
    
    void transfer() {
        if (sk_front.empty() ) {
            while (!sk_back.empty() ) {
                sk_front.push(sk_back.top() );
                sk_back.pop();
            }
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        sk_back.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        transfer();
        sk_front.pop();
    }

    // Get the front element.
    int peek(void) {
        transfer();
        return sk_front.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return sk_front.empty() && sk_back.empty();
    }
};
