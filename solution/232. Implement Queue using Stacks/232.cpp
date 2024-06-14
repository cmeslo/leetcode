class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        A.push(x);
    }
    
    int pop() {
        int x = peek();
        B.pop();
        return x;
    }
    
    int peek() {
        if (B.empty()) {
            while (!A.empty()) {
                B.push(A.top());
                A.pop();
            }
        }
        return B.top();
    }
    
    bool empty() {
        return A.empty() && B.empty();
    }
    
private:
    stack<int> A, B;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
